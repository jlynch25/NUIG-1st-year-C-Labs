#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


FILE *openFile(char *fileName, char *mode);
void closeFile(FILE *fptr);

typedef struct
{
	char *firstName;
	char *lastName;
	char *company;
	char *address;
	char *city;
	char *county;
	char *state;
	char *zip;
	char *phone1;
	char *phone2;
	char *email;
	char *web;
}data;

void main(void)
{
	data data[550];
	int i = 0, j = 0, search = 1, num;
	char line[550];
	char delimiter[10] = ",";
	char *token;



	FILE *fptr;
	char fileName[] = "C:\\Users\\HP-\\Documents\\us-500b.txt";
	fptr = openFile(fileName, "r");

	for (j = 0; j < 1; j++) fgets(line, 550, fptr);

	while (!feof(fptr))
	{
		fgets(line, 550, fptr);

		token = strtok(line, delimiter);

		data[i].firstName = (char *)malloc(strlen(token) + 1);
		strcpy(data[i].firstName, token);
		token = strtok(NULL, delimiter);

		data[i].lastName = (char *)malloc(strlen(token) + 1);	//error
		strcpy(data[i].lastName, token);
		token = strtok(NULL, delimiter);

		data[i].company = (char *)malloc(strlen(token) + 1);
		strcpy(data[i].company, token);
		token = strtok(NULL, delimiter);

		data[i].address = (char *)malloc(strlen(token) + 1);
		strcpy(data[i].address, token);
		token = strtok(NULL, delimiter);

		data[i].city = (char *)malloc(strlen(token) + 1);
		strcpy(data[i].city, token);
		token = strtok(NULL, delimiter);

		data[i].county = (char *)malloc(strlen(token) + 1);
		strcpy(data[i].county, token);
		token = strtok(NULL, delimiter);

		data[i].state = (char *)malloc(strlen(token) + 1);
		strcpy(data[i].state, token);
		token = strtok(NULL, delimiter);

		data[i].zip = (char *)malloc(strlen(token) + 1);
		strcpy(data[i].zip, token);
		token = strtok(NULL, delimiter);

		data[i].phone1 = (char *)malloc(strlen(token) + 1);
		strcpy(data[i].phone1, token);
		token = strtok(NULL, delimiter);

		data[i].phone2 = (char *)malloc(strlen(token) + 1);
		strcpy(data[i].phone2, token);
		token = strtok(NULL, delimiter);

		data[i].email = (char *)malloc(strlen(token) + 1);
		strcpy(data[i].email, token);
		token = strtok(NULL, delimiter);

		data[i].web = (char *)malloc(strlen(token) + 1);
		strcpy(data[i].web, token);
		token = strtok(NULL, delimiter);

		//for a check
		//printf("%s %s %s %s %s %s %s\n", data[i].firstName, data[i].lastName, data[i].company, data[i].address, data[i].zip, data[i].phone1, data[i].web);
		i++;

	}

	closeFile(fptr);

	num = i;	//number of  people

	printf("Database search by:\n\t1)\tName\n\t2)\tCompany\n\t3)\tcity\n\n");
	scanf("%d", search);


	while (search != 0) {
		char temp[20];
		char *ptr;
		switch (search) {

		case 1: {
			puts("Enter all <or part> of the first or last name of the person that you would like to search for:\n");
			gets_s(temp);
			i = 0;
			while (temp[i]) {
				putchar(toupper(temp[i]));
				i++;
			}

			for (j = 0; j < num + 1; j++)
			{
				putchar(toupper(*data[j].firstName));

				ptr = strstr(data[j].firstName, temp);

				if (ptr)
				{
					printf("fisrt name: %s\nlast name: %s\ncompany: %s\ncity %s\ncounty: %s\nstate: %s\nzip: %s\nphone 1: %s\nphone 2: %s\nemail: %s\nweb: %s\n\n\n", data[j].firstName, data[j].lastName, data[j].company, data[j].address, data[j].city, data[j].county, data[j].state, data[j].zip, data[j].phone1, data[j].phone2, data[j].email, data[j].web);
				}
			}
			for (j = 0; j < num + 1; j++)
			{
				putchar(toupper(*data[j].lastName));
				
				ptr = strstr(data[j].lastName, temp);
				if (ptr)
				{
					printf("fisrt name: %s\nlast name: %s\ncompany: %s\ncity %s\ncounty: %s\nstate: %s\nzip: %s\nphone 1: %s\nphone 2: %s\nemail: %s\nweb: %s\n\n\n", data[j].firstName, data[j].lastName, data[j].company, data[j].address, data[j].city, data[j].county, data[j].state, data[j].zip, data[j].phone1, data[j].phone2, data[j].email, data[j].web);
				}
			}

			break;
		}

		case 2: {
			puts("Enter all <or part> of the company name that you would like to search for:\n");
			gets_s(temp);
			i = 0;
			while (temp[i]) {
				putchar(toupper(temp[i]));
				i++;
			}

			for (j = 0; j < num + 1; j++)
			{
				putchar(toupper(*data[j].company));

				ptr = strstr(data[j].company, temp);

				if (ptr)
				{
					printf("fisrt name: %s\nlast name: %s\ncompany: %s\ncity %s\ncounty: %s\nstate: %s\nzip: %s\nphone 1: %s\nphone 2: %s\nemail: %s\nweb: %s\n\n\n", data[j].firstName, data[j].lastName, data[j].company, data[j].address, data[j].city, data[j].county, data[j].state, data[j].zip, data[j].phone1, data[j].phone2, data[j].email, data[j].web);
				}
			}
			break;
		}

		case 3: {
			puts("Enter all <or part> of the city name that you would like to search for:\n");
			gets_s(temp);
			i = 0;
			while (temp[i]) {
				putchar(toupper(temp[i]));
				i++;
			}

			for (j = 0; j < num + 1; j++)
			{
				putchar(toupper(*data[j].city));

				ptr = strstr(data[j].city, temp);

				if (ptr)
				{
					printf("fisrt name: %s\nlast name: %s\ncompany: %s\ncity %s\ncounty: %s\nstate: %s\nzip: %s\nphone 1: %s\nphone 2: %s\nemail: %s\nweb: %s\n\n\n", data[j].firstName, data[j].lastName, data[j].company, data[j].address, data[j].city, data[j].county, data[j].state, data[j].zip, data[j].phone1, data[j].phone2, data[j].email, data[j].web);
				}
			}
			break;
		}

		default: {
			printf("Invalid input\n");
		}

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



