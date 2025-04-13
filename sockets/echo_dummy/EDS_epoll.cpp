#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <sys/epoll.h>

#define PORT                3230
#define INIT_DELAY          15
#ifndef MAX_BUFFER_SIZE
    #define MAX_BUFFER_SIZE 1024
#endif
#ifndef EPOLL_SIZE
    #define EPOLL_SIZE 2048
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

void do_process(int socket)
{
    char buff[MAX_BUFFER_SIZE];
    bzero(buff, sizeof(buff));

    int msg_size = recv(socket, (char*)buff, MAX_BUFFER_SIZE, MSG_NOSIGNAL);

    if ((strncmp(buff, "exit", 4)) == 0 || (msg_size == 0 && errno != EAGAIN)) {
        printf("Client leaved\n");
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

    struct epoll_event event;
    struct epoll_event events[EPOLL_SIZE];

    int epoll_fd = epoll_create1(0);
    if (epoll_fd == -1) {
        printf("Failed to create epoll instance\n");
        return 1;
    }

    event.events = EPOLLIN;
    event.data.fd = server_socket;

    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, server_socket, &event)) {
        printf("Failed to add master socket's event\n");
        return 1;
    }

    while(true) {

        int event_count = epoll_wait(epoll_fd, events, EPOLL_SIZE, -1);

        for(size_t i = 0; i < event_count; i++) {
            if (events[i].data.fd != server_socket){
                do_process(events[i].data.fd);
            } else {
                const auto socket = accept(events[i].data.fd, 0, 0);
                printf("Client joined\n");
                setNonblock(socket);

                struct epoll_event added_event;
                added_event.events = EPOLLIN;
                added_event.data.fd = socket;

                if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, socket, &added_event)) {
                    printf("Failed to add working socket's event\n");
                    //return 1;
                }
            }
        }
    }

    if (close(epoll_fd)) {
        printf("Failed to close epoll instance\n");
        return 1;
    }

    return 0;
}
