#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "time.h"

FILE *openFile(char *fileName, char *mode);
void closeFile(FILE *fptr);


void main(void)
{
	struct date
	{
		int day, month, year;
	};
	struct student
	{
		int studentID;
		char firstName[20];
		char lastName[20];
		char courseID[10];
		int year;
		struct date registrationDate;
		struct date dateOfBirth;
		int averageGrade;
	};

	struct student student[10];

	int i=0,random;
	srand(time(NULL));

	FILE *fptr;
	char fileName[] = "C:\\Users\\HP-\\Documents\\students.txt";

	
	fptr = openFile(fileName, "r");
	
	while (!feof(fptr))
	{
		fscanf(fptr, "%d\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", &student[i].studentID, student[i].firstName, student[i].lastName, student[i].courseID, &student[i].year, &student[i].registrationDate.day, &student[i].registrationDate.month, &student[i].registrationDate.year, &student[i].dateOfBirth.day, &student[i].dateOfBirth.month, &student[i].dateOfBirth.year);
		random = rand() % 101;
		student[i].averageGrade = random;
		i++;
	}

	closeFile(fptr);




fptr = openFile(fileName, "w");

fprintf(fptr, "%d\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", student[0].studentID, student[0].firstName, student[0].lastName, student[0].courseID, student[0].year, student[0].registrationDate.day, student[0].registrationDate.month, student[0].registrationDate.year, student[0].dateOfBirth.day, student[0].dateOfBirth.month, student[0].dateOfBirth.year, student[0].averageGrade);
fprintf(fptr, "%d\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", student[1].studentID, student[1].firstName, student[1].lastName, student[1].courseID, student[1].year, student[1].registrationDate.day, student[1].registrationDate.month, student[1].registrationDate.year, student[1].dateOfBirth.day, student[1].dateOfBirth.month, student[1].dateOfBirth.year, student[1].averageGrade);

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
