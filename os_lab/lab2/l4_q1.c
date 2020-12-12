#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char** argv)
{
	struct stat sb;
	int ret;
	ret = stat(argv[1], &sb);
	if (ret) {
		perror("unable to fetch stat");
		return 1;
	}	
	printf("Inode: %ld\n", sb.st_ino);
	return 0;
}