#include <stdio.h>
#include <stdlib.h>

char fileError[] = "Error opening file:";
char memoryError[] = "Error with memory:";
char readError[] = "Error reading file:";

char* open_script(char scriptName[]){
    FILE *fp;
    int c, i, max;

    fp = fopen(scriptName, "rb");
    if (fp == NULL) fprintf(stderr, "cannot open input file\n");
	char* buffer;
	buffer = (char*) malloc (sizeof(char)*ftell (fp));
	//if (buffer==NULL) error(memoryError, scriptName, 2);
    fclose(fp);
	return buffer;
}