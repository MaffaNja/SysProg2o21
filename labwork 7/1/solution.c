#include<stdio.h>

int main(int argc, char *argv[]) {

	FILE *pipe;
	char buf[1024];
	sprintf(buf, "%s %s", argv[1], argv[2]);
	pipe = popen(buf, "r");

	if (!pipe) {
		fprintf(stderr, "Error opening pipe!\n");
		return 1;
	}

	int count = 0;
	while (!feof(pipe)) {
		char c = fgetc(pipe);
		if (c == '0') count++;
	}

	if (pclose(pipe) == -1) {
		fprintf(stderr," Error!\n");
		return 1;
	}
	
	printf("%d\n", count);
	return 0;
}
