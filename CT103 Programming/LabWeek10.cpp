#include <stdio.h>
#include "stdafx.h"
#include "string.h"

void printShortestName(char name[][100], int num);
void printLongestName(char name[][100], int num);

int main()
{
	int i = 1;
	int j = 0;
	int noNames = 0;
	char name[100][100];
	char dooby[100];

	printf("how many names do you want to enter?\n");
	scanf_s("%d", &noNames);
	gets_s(dooby);
	for (i = 0; i < noNames; i++)
	{
		printf("enter name  #%d ?\n", i+1);
		gets_s(name[i]);

		
	}
	printShortestName(name, noNames);
	printLongestName(name, noNames);
}

void printShortestName(char name[][100], int noName)
{
	int length = 100;
	char Name[100];

	for (int i = 0; i < noName; i++)
		if(strlen(name[i]) < length)
		{
			length = strlen(name[i]);
			strcpy_s(Name, name[i]);
		}
	if (length == 1) { printf("shortest name is %d character long, it is %s\n", length, Name); }
	else { printf("shortest name is %d characters long, it is %s\n", length, Name); }
};

void printLongestName(char name[][100], int noName)
{
	int length = 0;
	char Name[100];

	for (int i = 0; i < noName; i++)
		if (strlen(name[i]) > length )
		{
			length = strlen(name[i]);
			strcpy_s(Name, name[i]);
		}
	if (length == 1) { printf("longest name is %d character long, it is %s\n", length, Name); }
	else { printf("longest name is %d characters long, it is %s\n", length, Name); }
};