#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <wait.h>

int main(int argc, char *argv[])
{
	int fd[2];
	pid_t pid;
	char buf;
	if(argc!=2)
	{
		printf("Invalid no. of arguments\n");
		exit(EXIT_FAILURE);
	}
	if(pipe(fd)==-1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if(pid==-1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if(pid==0) //child process
	{
		printf("Reading in child...\n");
		close(fd[1]); //close unused write end
		while(read(fd[0], &buf, 1)>0)
			write(STDOUT_FILENO, &buf, 1);
		write(STDOUT_FILENO, "\n", 1);
		close(fd[0]);
		printf("Child ended\n");
		exit(EXIT_SUCCESS);
	}
	else //parent process
	{
		printf("Writing in parent...\n");
		close(fd[0]); //close unused read end
		write(fd[1], argv[1], strlen(argv[1]));
		close(fd[1]); //reader will see EOF
		wait(NULL); //wait for child to terminate
		printf("Parent ended\n");
		exit(EXIT_SUCCESS);
	}
	return 0;
}