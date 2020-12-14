#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	char* file = argv[1];
	char* out_file = argv[2];
	FILE *fp = fopen(file, "r");
	if (fp == NULL) {
		printf("Cannot open file.\n");
		exit(0);
	}
	FILE *out = fopen(out_file, "w");
	char c;
	while ((c = getc(fp)) != EOF) {
		if (c == ' ' || c == '\t') {
			putc(c, out);
			while((c=getc(fp))!=EOF && (c==' '||c=='\t'));
			putc(c, out);
		}
		else putc(c, out);
	}
	return 0;
}