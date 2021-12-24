#include <stdio.h>
#include <unistd.h>

int main()
{
	system("pidof -c genenv | wc -w");
}
