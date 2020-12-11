#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

void main() {
	int status;
	pid_t pid;
	pid = fork();
	if (pid == -1){
		printf("ERROR child not created\n"); 
	}
	else if (pid == 0) {
		printf("I'm the child\n");
		for (int i = 0; i < 10000; ++i);
		exit(0);
	}
	else {
		wait(&status);
		printf("I'm the parent!\n");
		printf("Child returned %d\n", status);
	}
}