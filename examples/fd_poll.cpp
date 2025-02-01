#include <stdio.h>
#include <sys/poll.h>
#include <unistd.h>

#define TIMEOUT 5

int main()
{
    struct pollfd fds[2];

    fds[0].fd = 0;
    fds[0].events = POLLIN;

    int ret = poll(fds, 1, TIMEOUT*1000);

    if (ret) {
        printf("Data is ready\n");

        if (fds[0].revents & POLLIN){
            char buf[1024];
            scanf("%s", buf);
            printf("%s\n", buf);
        }
    } else {
        printf("TIMEOUT\n");
    }

    return 0;
}

