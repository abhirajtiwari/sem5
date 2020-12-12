#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void printWordLine(char* word, int buff_size, char buff[]) {
    char c[80];
    int j = 0;
    int line_number = 1;
    for(int i = 0 ; i <= buff_size; i++) {
        if(buff[i] == '\n') {
            c[j++] = '\0';
            char* p = strstr(c, word);
            if(p) {
                printf("line %d : %s \n", line_number, c);
            }
            j = 0;
            line_number++;
        } else {
            c[j++] = buff[i];
        }
    }
}

int main(int argc, char** argv) {
    char buff[100];
    char* word = argv[1];
    char* filename = argv[2];
    int fd = open(filename, O_RDONLY);
    int buff_size = read(fd, buff, sizeof(buff));
    if(buff_size == -1) {
        printf("ERROR");
        exit(1);
    }
    printWordLine(word, buff_size, buff);
    return 0;
}
