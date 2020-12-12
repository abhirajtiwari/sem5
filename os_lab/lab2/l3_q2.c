#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

void main() {
	pid_t pid;
	int status;
	pid = fork();
	if (pid==0)
	{
		execvp("./q1",NULL);
	}
	else if (pid == -1) {
		perror("Fork unsuccessfull");
	}
	else {
		wait(&status);
		exit(0);
	}
}