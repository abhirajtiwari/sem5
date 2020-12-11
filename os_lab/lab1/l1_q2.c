#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int printFile(int buff_size, char buff[]) {
	int lines = 0;
	for (int i = 0; i < buff_size; ++i) {
		printf("%c", buff[i]);
		if (buff[i]=='\n') lines++;
		if (lines == 20) {getchar(); lines=0;}
	}
}

int main(int argc, char ** argv) {
	char buff[1000];
	char* file_name = argv[1];
	int fd = open(file_name, O_RDONLY);
	int buff_size = read(fd, buff, sizeof(buff));
	if (buff_size == -1) {
		printf("ERROR\n");
		exit(-1);
	}
	printFile(buff_size, buff);
	return 0;
}