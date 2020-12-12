#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
	char* filename1 = argv[1];
	char* filename2 = argv[2];
	char cp;
	int f1 = open(filename1, O_RDONLY);
	int f2 = open(filename2, O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
	while (read(f1, &cp, 1)==1 && cp != EOF) write(f2, &cp, 1);
}