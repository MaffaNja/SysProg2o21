#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE 5000

int main(int argc, char **argv) {
    struct sockaddr_in local;
    int s = socket(AF_INET, SOCK_DGRAM, 0);
    int nb;
    char buf[BUFSIZE];

    if (argc != 2)
        goto user_error;

    inet_aton("127.0.0.1", &local.sin_addr);
    local.sin_port = htons(atoi(argv[1]));
    local.sin_family = AF_INET;

    if (bind(s, (struct sockaddr *) &local, sizeof(local)))
        goto bind_error;

    for (;;) {
        nb = read(s, buf, BUFSIZE - 1);
        if (nb == -1)
            goto read_error;
        buf[nb] = 0;
        if (!strcmp(buf, "OFF\n"))
            goto out;
        printf("%s\n", buf);
    }

    user_error:
    fprintf(stderr, "usage: %s <port>\n", argv[0]);
    return -1;
    bind_error:
    perror("bind");
    return -1;
    read_error:
    perror("read");
    return -1;
    out:
    close(s);
    return 0;
}

