#include <arpa/inet.h>
#include <stdbool.h>
#include <stdio.h>

struct sockaddr_in local;

int CharCompare(const char *lhs, const char *rhs) {
    if (*lhs == *rhs)
        return 0;
    return *rhs > *lhs;
}

void Server(int port) {
    int s = socket(AF_INET, SOCK_STREAM, 0);

    inet_aton("127.0.0.1", &local.sin_addr);
    local.sin_port = htons(port);
    local.sin_family = AF_INET;

    int result = bind(s, (struct sockaddr *) &local, sizeof(local));

    int clientsMaxCount = 5;
    result = listen(s, clientsMaxCount);

    int cs = accept(s, NULL, NULL);
    char buffer[BUFSIZ];
    const char *endString = "OFF";

    while (true) {
        read(cs, buffer, BUFSIZ);

        if (strncmp(buffer, endString, strlen(endString)) == 0)
            return;

        qsort(buffer, strlen(buffer), 1, CharCompare);

        write(cs, buffer, strlen(buffer) + 1);
    }

    close(cs);
}


int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Format: %s port \n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

    Server(port);

    return 0;
}
