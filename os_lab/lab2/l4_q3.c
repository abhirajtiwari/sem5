#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	link(argv[1], argv[2]);
	printf("new path is %s", argv[2]);
	getchar();
	unlink(argv[2]);
	printf("file unlinked");
	return 0;
}