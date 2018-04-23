#include "stdafx.h"
#include <stdio.h>


FILE *openFile(char *fileName, char *mode);
void closeFile(FILE *fptr);

void main(void)
{

	FILE *fptr;
	char fileName[] = "C:\\Users\\HP-\\Documents\\xyz.txt";
	fptr = openFile(fileName, "r");


	closeFile(fptr);
}


FILE * openFile(char *fileName, char *mode)
{

	FILE *fptr = fopen(fileName, mode);

	if (fptr == NULL)
	{
		printf("Error opening file ! \n");
	}

	return fptr;
}

void closeFile(FILE *fptr)
{
	fclose(fptr);
}
