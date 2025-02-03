#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>

int main()
{
    fd_set rd_fds;
    struct timeval tv;

    FD_ZERO(&rd_fds);
    FD_SET(0, &rd_fds);

    tv.tv_sec = 5;
    tv.tv_usec = 0;
    int max_num = 1;

    int ret = select(max_num, &rd_fds, NULL, NULL, &tv);

    if (ret) {
        printf("Data is ready\n");

        printf("FD_ISSET status: %u\n", FD_ISSET(0, &rd_fds));

        if (FD_ISSET(0, &rd_fds)){
            char buf[1024];
            scanf("%s", buf);
            printf("%s\n", buf);
        }
    } else {
        printf("TIMEOUT\n");
    }

    return 0;
}

