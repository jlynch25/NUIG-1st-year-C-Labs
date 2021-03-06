#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>



typedef struct
{
	char *UserName;
	char *firstName;
	char *lastName;
	char *displayName;
	char *jobTitle;
	char *department;
	char *officeNumber;
	char *officePhone;
	char *mobilePhone;
	char *fax;
	char *address;
	char *city;
	char *state;
	char *zip;
	char *country;
} contact;


void printContact(contact *data, int i);
FILE *openFile(char *fileName, char *mode);
void closeFile(FILE *fptr);


void main(void)
{
	contact data[550];
	int i = 0, j = 0;
	char line[550];
	char delimiter[10] = ",";
	char *token;



	FILE *fptr;
	char fileName[] = "C:\\Users\\HP-\\Documents\\contacts.txt";
	fptr = openFile(fileName, "r");

	for (j = 0; j < 1; j++) fgets(line, 550, fptr);

	while (!feof(fptr))
	{
		fgets(line, 550, fptr);

		token = strtok(line, delimiter);

		data[i].UserName = (char *)malloc(strlen(token) + 1);
		strcpy(data[i].UserName, token);
		token = strtok(NULL, delimiter);

		data[i].firstName = (char *)malloc(strlen(token) + 1);	
		strcpy(data[i].firstName, token);
		token = strtok(NULL, delimiter);

		data[i].lastName = (char *)malloc(strlen(token) + 1);
		strcpy(data[i].lastName, token);
		token = strtok(NULL, delimiter);

		data[i].displayName = (char *)malloc(strlen(token) + 1);
		strcpy(data[i].displayName, token);
		token = strtok(NULL, delimiter);

		data[i].jobTitle = (char *)malloc(strlen(token) + 1);
		strcpy(data[i].jobTitle, token);
		token = strtok(NULL, delimiter);

		data[i].department = (char *)malloc(strlen(token) + 1);
		strcpy(data[i].department, token);
		token = strtok(NULL, delimiter);

		data[i].officeNumber = (char *)malloc(strlen(token) + 1);
		strcpy(data[i].officeNumber, token);
		token = strtok(NULL, delimiter);

		data[i].officePhone = (char *)malloc(strlen(token) + 1);
		strcpy(data[i].officePhone, token);
		token = strtok(NULL, delimiter);

		data[i].mobilePhone = (char *)malloc(strlen(token) + 1);
		strcpy(data[i].mobilePhone, token);
		token = strtok(NULL, delimiter);

		data[i].fax = (char *)malloc(strlen(token) + 1);
		strcpy(data[i].fax, token);
		token = strtok(NULL, delimiter);

		data[i].address = (char *)malloc(strlen(token) + 1);
		strcpy(data[i].address, token);
		token = strtok(NULL, delimiter);

		data[i].city = (char *)malloc(strlen(token) + 1);
		strcpy(data[i].city, token);
		token = strtok(NULL, delimiter);

		data[i].state = (char *)malloc(strlen(token) + 1);
		strcpy(data[i].state, token);
		token = strtok(NULL, delimiter);

		data[i].zip = (char *)malloc(strlen(token) + 1);
		strcpy(data[i].zip, token);
		token = strtok(NULL, delimiter);

		data[i].country = (char *)malloc(strlen(token) + 1);
		strcpy(data[i].country, token);
		token = strtok(NULL, delimiter);

		printContact(data,i);
		//printf("UserName: %s\nfisrt name : %s\nlast name : %s\ndisplayName : %s\njobTitle %s\ndepartment: %s\nofficeNumber : %s\nofficePhone : %s\nmobilePhone : %s\nfax : %s\naddress : %s\ncity : %s\nstate : %s\nzip : %s\ncountry : %s\n\n\n", data[i].UserName, data[i].firstName, data[i].lastName, data[i].displayName, data[i].jobTitle, data[i].department, data[i].officeNumber, data[i].officePhone, data[i].mobilePhone, data[i].fax, data[i].address, data[i].city, data[i].state, data[i].zip, data[i].country);
		//printf("%s %s %s %s %s %s %s%s %s %s %s %s %s %s %s\n", data[i].UserName,data[i].firstName, data[i].lastName, data[i].displayName, data[i].jobTitle, data[i].department, data[i].officeNumber, data[i].officePhone, data[i].mobilePhone, data[i].fax, data[i].address, data[i].city, data[i].state, data[i].zip, data[i].country);
		i++;

	}
	closeFile(fptr);
}


void printContact(contact *data,int i)
{
	printf("UserName: %s\nfisrt name : %s\nlast name : %s\ndisplayName : %s\njobTitle %s\ndepartment: %s\nofficeNumber : %s\nofficePhone : %s\nmobilePhone : %s\nfax : %s\naddress : %s\ncity : %s\nstate : %s\nzip : %s\ncountry : %s\n\n\n", data[i].UserName, data[i].firstName, data[i].lastName, data[i].displayName, data[i].jobTitle, data[i].department, data[i].officeNumber, data[i].officePhone, data[i].mobilePhone, data[i].fax, data[i].address, data[i].city, data[i].state, data[i].zip, data[i].country);

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

