#include "script.h"

//flags


char* open_script(char scriptName[]){
	FILE* fp = fopen(scriptName, "rb");
	if (fp == NULL) fprintf(stderr, FILE_ERR);
	char* buffer = (char*) malloc (sizeof(char)*ftell (fp));
	if (buffer==NULL) fprintf(stderr, MEM_ERR);
	fclose(fp);
	return buffer;
}

char GETCMD(char* script, u8 i){
	return script[i];
}