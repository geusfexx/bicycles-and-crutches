#include <stdio.h>
#include <sys/epoll.h>
#include <unistd.h>

#define TIMEOUT 5000

int main()
{
    const char* quit = "FLUGGAENKDECHIOEBOLSEN";
    struct epoll_event event;
    struct epoll_event events[5];
    char buf[1024];
    int len_rd;
    int epoll_fd = epoll_create1(0);


    if (epoll_fd == -1) {
        printf("Failed to create\n");
        return 1;
    }

    event.events = EPOLLIN;
    event.data.fd = 0;

    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, 0, &event)) {
        printf("Failed to add\n");
        return 1;
    }

    int event_count = epoll_wait(epoll_fd, events, 1, TIMEOUT);
    if (event_count) {
        for (int i(0); i < event_count; i++) {
            printf("Handling file descriptor: %u\n", events[i].data.fd);
            len_rd = read(events[i].data.fd, buf, sizeof(buf));
            buf[len_rd] = '\0';
            printf("%s", buf);
        }

    } else {
        printf("TIMEOUT\n");
    }

    if (close(epoll_fd)) {
        printf("Failed to close'\n");
        return 1;
    }

    return 0;
}

