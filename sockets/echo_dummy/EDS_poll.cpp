#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>
#include <sys/time.h>
#include <sys/types.h>

#include <set>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <poll.h>

#define PORT                3230
#define INIT_DELAY          15
#ifndef MAX_BUFFER_SIZE
    #define MAX_BUFFER_SIZE 1024
#endif
#ifndef POLL_SIZE
    #define POLL_SIZE 2048
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

    struct pollfd pollfd_set[POLL_SIZE];
    pollfd_set[0].fd = server_socket;
    pollfd_set[0].events = POLLIN;

    while(true) {
        size_t index = 1;
        for (const auto& iter : worker_sockets) {
            pollfd_set[index].fd = iter;
            pollfd_set[index].events = POLLIN;
            index++;
        }

        size_t pollfd_set_size = worker_sockets.size() + 1;
        poll(pollfd_set, pollfd_set_size, -1);

        for(size_t i = 1; i < pollfd_set_size; i++) {
            if (pollfd_set[i].revents & POLLIN){
                bool socket_alive = true;
                do_process(pollfd_set[i].fd, socket_alive);

                if (!socket_alive) {
                    worker_sockets.erase(pollfd_set[i].fd);
                }
            }
        }

        if (pollfd_set[0].revents & POLLIN){
            const auto socket = accept(server_socket, 0, 0);
            printf("Client joined\n");
            setNonblock(socket);
            worker_sockets.insert(socket);
        }
    }

    return 0;
}
