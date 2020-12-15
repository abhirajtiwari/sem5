#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Less Arguments.\n");
        printf("Usage: %s <bin_file_name> <string_to_write_there>\n", argv[0]);
        exit(-1);
    }
    FILE* f = fopen(argv[1], "wb");
    fwrite(argv[2], strlen(argv[2]),1,f);
    close(f);
    printf("Written the file.\n\n");

    f = fopen(argv[1], "rb");
    char buff[strlen(argv[2])];
    fread(buff, strlen(argv[2]),1,f);
    for(int i = 0; i < strlen(argv[2]); ++i) printf("%x ", buff[i]);
    close(f);
    return 0;
}