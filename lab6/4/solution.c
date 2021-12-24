#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int getchildren(char *pid){
	int count=1;
	FILE * file;
	char * line = NULL;
	size_t len = 0;
	char   sPid[16], sPpid[16];
	file = popen("cat /proc/[0-9]*/status 2>/dev/null", "r");
	while (getline(&line, &len, file) > 0) {
		if (sscanf(line, "Pid:%s", sPid) == 1){
			getline(&line, &len, file);
			sscanf(line, "PPid:%s", sPpid);
			if (!strcmp(pid, sPpid))
				count += getchildren(sPid);
		} 
	}
	free(line);
	fclose(file);
	return count;
}
int main (int carg, char **argv){
	printf("%d\n", getchildren(argv[1]));
}
