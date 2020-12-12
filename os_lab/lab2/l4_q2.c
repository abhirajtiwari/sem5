#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	struct stat sb;
	int ret;
	if(argc < 2){
		fprintf(stderr, "usage: %s <file>\n", argv[0]);
		return 1;
	} 
	ret = stat(argv[1], &sb);
	if(ret) {
		perror("stat");
		return 1;
	}
	printf("st_dev: %ld\n", sb.st_dev);
	printf("st_ino: %ld\n", sb.st_ino);
	printf("st_size: %ld\n", sb.st_size);
	printf("st_uid: %d\n", sb.st_uid);
	printf("st_nlink: %ld\n", sb.st_nlink);
	return 0;
}