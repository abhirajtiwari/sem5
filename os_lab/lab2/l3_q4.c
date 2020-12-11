#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

void main() {
	pid_t pid;
	pid = fork();
	if (pid == 0) {
		printf("I'm child\n");
		printf("child end\n");
		exit(0);
	}
	else if (pid == -1) {
		perror("fork unsuccessfull");
	}
	else {
		printf("parent\n");
		clock_t start = clock();
		while (clock() < start+(10*1000000));
		printf("parent end\n");
		exit(0);
	}
}