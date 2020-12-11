#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

void main() {
	pid_t pid;
	int status;
	pid = fork();
	if (pid == -1) {
		perror("Fork unsuccessfull");
	}
	else if (pid == 0) {
		printf("I'm child and my process id is %d\n", getpid());
	}
	else {
		printf("I'm the parent process and my process id is %d\n", getpid());
		wait(&status);
	}
}