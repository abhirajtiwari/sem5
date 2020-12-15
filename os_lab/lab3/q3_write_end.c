#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>

#define FIFO_NAME "/tmp/my_fifo"

int main(int argc, char *argv[])
{
	int pipe_fd;
	int res;
	int open_mode = O_WRONLY;
	int num;

	if(access(FIFO_NAME, F_OK)==-1)
	{
		res = mkfifo(FIFO_NAME, 0777);
		if(res!=0)
		{
			fprintf(stderr, "Could not create fifo %s\n", FIFO_NAME);
			exit(EXIT_FAILURE);
		}
		printf("Fifo created\n");
	}
	printf("Process %d opening write-only FIFO\n", getpid());
	pipe_fd = open(FIFO_NAME, open_mode);

	if(pipe_fd!=-1)
	{
		printf("Enter no. to be sent: ");
		scanf("%d", &num);
		res = write(pipe_fd, &num, sizeof(int));
		if(res==-1)
		{
			fprintf(stderr, "Write error on pipe\n");
			exit(EXIT_FAILURE);
		}
		close(pipe_fd);
	}
	else
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	printf("Process %d finished\nBytes sent = %d\n", getpid(), res);
	exit(EXIT_SUCCESS);
	return 0;
}