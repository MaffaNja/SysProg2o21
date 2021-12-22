#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

	if (!fork()) {
		chdir("/");		
		setsid();	
		sleep(1000);	
	} 

	fclose(stdin);
	fclose(stdout);
	fclose(stderr);

	return 0;
}
