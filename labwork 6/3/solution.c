#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define STR_BUFF 512

int main(int argc, char **argv)
{
    FILE* fd;
    int pid = 0;
    char str_n[STR_BUFF] = {0};
    char str_p[STR_BUFF] = {0};

    if (argc < 2) {
        printf("Usage: %s <PID>\n", argv[0]);
        exit(EXIT_SUCCESS);
    }

    pid = atoi(argv[1]);

    printf("%d\n", pid);

    while (pid > 1) {
        sprintf(str_n, "/proc/%d/status", pid);
        fd = fopen(str_n, "r");
        if (fd) {
            while (!strstr(str_p, "PPid:")) {
                fgets(str_p, STR_BUFF, fd);
            }
            pid = atoi(strstr(str_p, "\t") + 1);
            printf("%d\n", pid);
            str_p[0] = 0;
            fclose(fd);
        }
        else {
            perror(str_n);
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
