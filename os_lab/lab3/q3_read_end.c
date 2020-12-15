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

int main()
{
	int pipe_fd;
	int res;
	int open_mode = O_RDONLY;
	int buf;

	printf("Process %d opening read-only FIFO\n", getpid());
	pipe_fd = open(FIFO_NAME, open_mode);

	if(pipe_fd!=-1)
	{
		res = read(pipe_fd, &buf, sizeof(int));
		printf("%d\n", buf);
		close(pipe_fd);
	}
	else
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	printf("Process %d finished\nBytes read = %d\n", getpid(), res);
	exit(EXIT_SUCCESS);
	return 0;
}