#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char *directives[] = {"#include","#define","#if"};

int is_directive(char *str)
{
	for(int i = 0; i < sizeof(directives)/sizeof(char *); i++)
	{
		int len = strlen(directives[i]);
		if(strncmp(str, directives[i], len) == 0)
			return 1;
	}
	return 0;
}

int main(int argc, char** argv)
{
	FILE *fa,*fb;
	char* input = argv[1];
	char* output = argv[2];

	fa = fopen(input, "r");
    fb = fopen(output, "w");

    if(fa == NULL || fb == NULL)
    {
    	perror("Invalid files\n");
        return 1;
    }
    char line[256];
	while(fgets(line, 256, fa))
	{
		if(!is_directive(line))
		{ 
			fputs(line, fb);
		}
	}
	fclose(fa);
    fclose(fb);
}