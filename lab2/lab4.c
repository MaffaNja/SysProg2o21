#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int game(char yChoice, char rChoice)
{
    if (yChoice == rChoice)
        return -1;
    if (yChoice == 'r' && rChoice == 'p')
        return 0;
    else if (yChoice == 'p' && rChoice == 'r')
        return 1;
    if (yChoice == 'r' && rChoice == 's')
        return 1;
    else if (yChoice == 's' && rChoice == 'r')
        return 0;
    if (yChoice == 'p' && rChoice == 's')
        return 0;
    else if (yChoice == 's' && rChoice == 'p')
        return 1;
}

int main()
{
    int n, s;
    char rChoice, yChoice;
    char var[3] = {'r', 'p', 's'};
    printf("Enter r for ROCK p for PAPER and s for SCISSOR\n");
    scanf("%1s", &yChoice);
    srand(time(NULL));
    n = rand()%3;
    rChoice = var[n];
    printf("rChoice: %c\n", rChoice);
    s = game(yChoice, rChoice);
    switch(s)
    {
        case -1:
        {
            printf("Draw\n");
            break;
        }
        case 1:
        {
            printf("You won!\n");
            break;
        }
        case 0:
        {
            printf("You've lost...\n");
            break;
        }
    }
    return 0;
}
