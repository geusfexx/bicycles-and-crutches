#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>

#define PORT                3230
#define INIT_DELAY          15
#ifndef MAX_BUFFER_SIZE
    #define MAX_BUFFER_SIZE 1024
#endif

int client_init(){
    printf("Client initialisation started...\n");
    //sleep(INIT_DELAY);

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket <2) {
         printf("Socket creation failed...\n");
         exit(0);
    } else {
        printf("Socket successfully created..\n");
    }

    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    saddr.sin_port = htons(PORT);

    if (connect(client_socket, (struct sockaddr*)(&saddr), sizeof(saddr))) {
        printf("Connection failed...\n");
        exit(0);
    } else {
        printf("Connection established..\n");
    }

    printf("Initialisation has been completed. Client is ready.\n");

    return client_socket;
}

int main(int argc, char** argv) {

    int client_socket = client_init();
    char buff[MAX_BUFFER_SIZE];

    while(true) {

        int msg_size = 0;
        bzero(buff, sizeof(buff));
        printf("Enter message : ");

        while ((buff[msg_size++] = getchar()) != '\n') {}

        buff[msg_size] = '\0';
        send(client_socket, (char*)buff, msg_size, MSG_NOSIGNAL);
        if ((strncmp(buff, "exit", 4)) == 0) {
            printf("Exit confirmed\n");
            break;
        }
        bzero(buff, sizeof(buff));
        recv(client_socket, (char*)buff, MAX_BUFFER_SIZE, MSG_NOSIGNAL);
        printf("Server's respond: %s\n", buff);


    }

    shutdown(client_socket, SHUT_RDWR);
    close(client_socket);

    return 0;
}
