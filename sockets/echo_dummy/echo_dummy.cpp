#include <unistd.h>
#include <netinet/in.h>
#include <iostream>

#define PORT                3232
#define INIT_DELAY          15
#ifndef MAX_BUFFER_SIZE
    #define MAX_BUFFER_SIZE 1024
#endif

int server_init(){
    printf("Server initialisation started...\n");
    sleep(INIT_DELAY);

    int fd_server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (fd_server_socket <1) {
         printf("Socket creation failed...\n");
         exit(0);
    } else {
        printf("Socket successfully created..\n");
    }

    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);
    saddr.sin_port = htons(PORT);

    if (bind(fd_server_socket, (struct sockaddr*)(&saddr), sizeof(saddr))) {
        printf("Socket binding failed...\n");
        exit(0);
    } else {
        printf("Socket successfully binded..\n");
    }

    if (listen(fd_server_socket, SOMAXCONN)) {
        printf("Listening failed...\n");
        exit(0);
    } else {
        printf("Server started listening..\n");
    }

    printf("Initialisation has been completed. Server is ready.\n");

    return fd_server_socket;
}

int main(int argc, char** argv) {

    int server_socket = server_init();

    while(true) {
        int worker_socket = accept(server_socket, 0, 0);
        char buff[MAX_BUFFER_SIZE];
        int n = recv(worker_socket, (char*)buff, MAX_BUFFER_SIZE, MSG_NOSIGNAL);
        buff[n] = '\0';

        shutdown(worker_socket, SHUT_RDWR);
        close(worker_socket);

        if (n < 0) break;
        printf("%s\n", buff);
    }

    return 0;
}
