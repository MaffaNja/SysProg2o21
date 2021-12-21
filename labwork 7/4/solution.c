#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>


sig_atomic_t Exit = 0;


void Handler(int sigNum)
{
    Exit = 1; 
}


int main() 
{
    if(daemon(false, true) == 0)
    {
        printf("%d\n", getpid());

        fclose(stdin);
        fclose(stdout);
        fclose(stderr);

        signal(SIGURG, Handler);

        while(Exit == 0)
        {
            sleep(100);
        }
    }
    return 0;
}
