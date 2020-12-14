#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char *keywords[33] = {"auto", "double", "int", "struct", "break", "else", "long", "switch", "case", "enum", "register", "typedef",
    "char", "extern", "return", "union", "continue", "for", "signed", "void", "do", "if", "static", "while", "default", "goto", "sizeof",
    "volatile", "const", "float", "short", "unsigned", "printf"};

int isKeyword (char *word)
{
    for (int i=0; i<33; i++) {
        if (strcmp(word, keywords[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char** argv) {
	char* in = argv[1];

	FILE* in_fd = fopen(in, "r");

	if (in_fd == NULL) {
		perror("ERROR");
		exit(0);
	}

	char* buffer;
	buffer = (char *)malloc(1024*sizeof(char));
    int k;
    const char delimiters[] = " .,;:*&!?-_(){}[]\n\t";

    while (fgets(buffer, 1024, in_fd)!=NULL) {
        char *token = (char *)malloc(256 * sizeof(char));
        while((token = strsep(&buffer, delimiters)))
        {
            if(isKeyword(token))
            {
                for (int i=0; i<strlen(token); i++)
                    printf("%c", toupper(token[i]));
                printf("\n");
            }
        }
        free(buffer);
        buffer = (char *)malloc(1024*sizeof(char));
    }

    fclose(in_fd);
    return 0;
}