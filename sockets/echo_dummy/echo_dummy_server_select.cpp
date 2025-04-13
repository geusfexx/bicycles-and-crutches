#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>
#include <sys/time.h>
#include <sys/types.h>
#include <algorithm>
#include <set>
#include <sys/ioctl.h>
#include <fcntl.h>

#define PORT                3230
#define INIT_DELAY          15
#ifndef MAX_BUFFER_SIZE
    #define MAX_BUFFER_SIZE 1024
#endif

// Set socket to non-blocking mode
int setNonblock(int fileDescriptor)
{
    int flags;
#if defined(O_NONBLOCK)
    if (-1 == (flags = fcntl(fileDescriptor, F_GETFL, 0)))
        flags = 0;
    return fcntl(fileDescriptor, F_SETFL, O_NONBLOCK);
#else
    flags = 1;
    return ioctl(fileDescriptor, FIONBIO, &flags);
#endif
}

int server_init()
{
    //sleep(INIT_DELAY);

    int fd_server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (fd_server_socket <2) {
         printf("Socket creation failed...\n");
         exit(0);
    }

    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);
    saddr.sin_port = htons(PORT);

    if (bind(fd_server_socket, (struct sockaddr*)(&saddr), sizeof(saddr))) {
        printf("Socket binding failed...\n");
        exit(0);
    }

    if (listen(fd_server_socket, SOMAXCONN)) {
        printf("Listening failed...\n");
        exit(0);
    }

    printf("Initialisation has been completed. Server is ready.\n");

    return fd_server_socket;
}

void do_process(int socket, bool& socket_alive)
{
    char buff[MAX_BUFFER_SIZE];
    bzero(buff, sizeof(buff));

    int msg_size = recv(socket, (char*)buff, MAX_BUFFER_SIZE, MSG_NOSIGNAL);

    if ((strncmp(buff, "exit", 4)) == 0 || (msg_size == 0 && errno != EAGAIN)) {
        printf("Client leaved\n");
        socket_alive = false;
        shutdown(socket, SHUT_RDWR);
        close(socket);
        return;
    }

    buff[msg_size] = '\0';
    printf("Client message: %s", buff);
    send(socket, (char*)buff, msg_size, MSG_NOSIGNAL);
    printf("Server responded: %s\n", buff);

}

int main(int argc, char** argv) {

    const int server_socket = server_init();
    setNonblock(server_socket);
    std::set<int> worker_sockets;
    struct timeval tv;
    tv.tv_sec = 2;
    tv.tv_usec = 0;

    while(true) {

        fd_set rd_fds;
        FD_ZERO(&rd_fds);
        FD_SET(server_socket, &rd_fds);

        int max_num = server_socket;
        if (!worker_sockets.empty()) {
            max_num = std::max(max_num, *(worker_sockets.rbegin()));
            for (const auto& socket : worker_sockets) {
                FD_SET(socket, &rd_fds);
            }
        }

        if (select(max_num + 1, &rd_fds, NULL, NULL, &tv)) {
            if (FD_ISSET(server_socket, &rd_fds)) {
                const auto socket = accept(server_socket, 0, 0);
                printf("Client joined\n");
                setNonblock(socket);
                worker_sockets.insert(socket);
            }

            for (auto iter = worker_sockets.begin(); iter != worker_sockets.end(); ) {
                if (FD_ISSET(*iter, &rd_fds)) {
                    bool socket_alive = true;
                    do_process(*iter, socket_alive);

                    if (!socket_alive) {
                        iter = worker_sockets.erase(iter);
                        continue;
                    }
                }
                iter++;
            }
        }
    }

    return 0;
}
