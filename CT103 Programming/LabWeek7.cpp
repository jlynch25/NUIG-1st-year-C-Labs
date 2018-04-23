#include "stdafx.h"
#include <stdio.h>
#include "string.h"

void main()
{
	int i, j;
	char fullName[100];
	char firstName[30], middleName[30], surname[30];
	char initial;

	printf("enter full name: ");

	gets_s(fullName);
	printf("Thank you %s\n\n", fullName);


	i = 0;
	do {
		firstName[i] = fullName[i];
		i++;
	} while (fullName[i] != ' ');
	firstName[i] = '\0';
	i++;

	j = 0;
	do {
		middleName[j] = fullName[i];
		if (j == 0) initial = middleName[j];		//for this program there is no need to get
		j++;										//the full middleName, but it could be
		i++;										//helpful if you where to extend the program 
	} while (fullName[i] != ' ');
	middleName[j] = '\0';
	i++;

	j = 0;
	do {
		surname[j] = fullName[i];
		i++;
		j++;
	} while (fullName[i] != '\0');
	surname[j] = '\0';



	printf(" %s %c %s \n", firstName, initial, surname);
}

