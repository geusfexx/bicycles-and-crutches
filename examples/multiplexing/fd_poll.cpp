#include <stdio.h>
#include <sys/poll.h>
#include <unistd.h>

#define TIMEOUT 5

int main()
{
    struct pollfd fds[2];
    const char* quit = "FLUGGAENKDECHIOEBOLSEN";
    fds[0].fd = 0;
    fds[0].events = POLLIN;

    while(true) {
        int ret = poll(fds, 1, TIMEOUT*1000);

        if (ret) {
            if (fds[0].revents & POLLIN){
                char buf[1024];
                scanf("%s", buf);
                if (*buf == *quit) {
                    printf("Exit code has been received\n");
                    break;
                }
                printf("Data is ready\n");
                printf("%s\n", buf);
            }
        } else {
            printf("TIMEOUT\n");
        }
    }

    return 0;
}

