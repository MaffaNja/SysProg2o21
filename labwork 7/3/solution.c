#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int usr1_c = 0;
int usr2_c = 0;

void usr1_handler(int sig) {
    usr1_c++;
}

void usr2_handler(int sig) {
    usr2_c++;
}

void term_handler(int sig) {
    printf("%d %d\n", usr1_c, usr2_c);
    exit(0);
}

int main(void) {

    signal(SIGUSR1, usr1_handler);
    signal(SIGUSR2, usr2_handler);
    signal(SIGTERM, term_handler);

    while (1) { ;
    }

    return 0;
}