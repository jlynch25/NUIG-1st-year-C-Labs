#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>



struct result
{
	char last[40];
	char first[40];
	int age;
	char email[40];
	struct result *next;
};


FILE *openFile(char *fileName, char *mode);
void closeFile(FILE *fptr);


void main(void)
{
	struct result *start_node, *new_node, *current_node, *temp;
	char line[500], delimiter[10] = ",", *token;
	int i = 0;

	start_node = NULL;
	new_node = (struct result *)malloc(sizeof(struct result));
	new_node->next = NULL;


	FILE *fptr;
	char fileName[] = "C:\\Users\\HP-\\Documents\\users.txt";
	fptr = openFile(fileName, "r");

	fgets(line, 500, fptr);

	while (!feof(fptr))
	{
		if (start_node == NULL)
		{
			start_node = new_node;
			current_node = new_node;
		}

		else if (!feof(fptr))
		{
			current_node->next = new_node;

			current_node = new_node;
		}
		else
		{
			current_node->next = NULL;
			break;
		}

		new_node = (struct result *)malloc(sizeof(struct result));

		fgets(line, 500, fptr);

		token = strtok(line, delimiter);

		strcpy(new_node->last, token);
		token = strtok(NULL, delimiter);

		strcpy(new_node->first, token);
		token = strtok(NULL, delimiter);

		new_node->age = atoi(token);
		token = strtok(NULL, delimiter);

		strcpy(new_node->email, token);
		token = strtok(NULL, delimiter);

	}

	closeFile(fptr);

	int age = 1;
	while (age != 0){
		printf("Enter the age of person which you would like to search for:");
		scanf("%d", &age);

		temp = start_node;

		while (temp != NULL)
		{
			if (temp->age == age) {
				printf("\nFirst Name: %s \nLast Name: %s \nEmail: %s\n", temp->first, temp->last, temp->email);
			}
			temp = temp->next;

		}

	}

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




if (strcmp(argv[2], "/p") == 0)
{

	FILE *fptr;
	char *fileName = argv[1], *mode = "r";
	fptr = openFile(fileName, mode);

	printf("\n");
	while (!feof(fptr))
	{
		fgets(line, 50, fptr);

		token = strtok(line, fileDelimiter);
		printf("Date : %s\t", token);
		token = strtok(NULL, fileDelimiter);
		printf("Employee ID : %s\t", token);
		token = strtok(NULL, fileDelimiter);
		printf("ClockIn time : %s\t", token);
		token = strtok(NULL, fileDelimiter);
		printf("ClockOut time : %s\n", token);
		token = strtok(NULL, fileDelimiter);

	}

}