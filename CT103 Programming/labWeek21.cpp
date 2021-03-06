#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Date
{
	int day;
	int month;
	int year;
};

struct Time
{
	int hour;
	int min;
};

struct worktime
{
	int employeeID;
	struct Date date;
	struct Time startTime;
	struct Time endTime;
};

FILE *openFile(char *fileName, char *mode);
void closeFile(FILE *fptr);



void main(int argc, char *argv[])
{

	struct worktime data[100];
	int i = 0, j = 0,searchID = 0, len = 0, month=0;
	char delimiter[] = "/ :", fileDelimiter[] = ", \"", line[100], *token, months[12][10] = { "January","February","March","April","May","June","July","August","September","October","November","December" };



	//print the input
	for (i = 0; i<argc; i++)
	{
		printf("%s ", argv[i]);

	}

	//	/a	append funtion
	if (strcmp(argv[2], "/a") == 0)
	{

		// read input into structure 
		for (i = 3, j = 0; i<argc; j++)
		{

			data[j].employeeID = atoi(argv[i]);
			i++;

			token = strtok(argv[i], delimiter);
			data[j].date.day = atoi(token);
			token = strtok(NULL, delimiter);
			data[j].date.month = atoi(token);
			token = strtok(NULL, delimiter);
			data[j].date.year = atoi(token);
			i++;

			token = strtok(argv[i], delimiter);
			data[j].startTime.hour = atoi(token);
			token = strtok(NULL, delimiter);
			data[j].startTime.min = atoi(token);
			i++;

			token = strtok(argv[i], delimiter);
			data[j].endTime.hour = atoi(token);
			token = strtok(NULL, delimiter);
			data[j].endTime.min = atoi(token);
			i++;

		}

		//now append to file
		FILE *fptr;
		char *fileName = argv[1], *mode = "a";
		fptr = openFile(fileName, mode);

		for (i = 0; i < j; i++) // now j = number of entrys
		{
			if (data[i].startTime.hour < 10 && data[i].startTime.min > 10 && data[i].endTime.hour > 10 && data[i].endTime.min > 10)	fprintf(fptr, "\"%s %d %d\",\"%d\",\"0%d:%d\",\"%d:%d\"\n", months[data[i].date.month], data[i].date.day, data[i].date.year, data[i].employeeID, data[i].startTime.hour, data[i].startTime.min, data[i].endTime.hour, data[i].endTime.min);
			else if (data[i].startTime.hour < 10 && data[i].startTime.min < 10 && data[i].endTime.hour > 10 && data[i].endTime.min > 10)	fprintf(fptr, "\"%s %d %d\",\"%d\",\"0%d:0%d\",\"%d:%d\"", months[data[i].date.month], data[i].date.day, data[i].date.year, data[i].employeeID, data[i].startTime.hour, data[i].startTime.min, data[i].endTime.hour, data[i].endTime.min);
			else if (data[i].startTime.hour < 10 && data[i].startTime.min < 10 && data[i].endTime.hour < 10 && data[i].endTime.min > 10)	fprintf(fptr, "\"%s %d %d\",\"%d\",\"0%d:0%d\",\"0%d:%d\"", months[data[i].date.month], data[i].date.day, data[i].date.year, data[i].employeeID, data[i].startTime.hour, data[i].startTime.min, data[i].endTime.hour, data[i].endTime.min);
			else if (data[i].startTime.hour < 10 && data[i].startTime.min < 10 && data[i].endTime.hour < 10 && data[i].endTime.min < 10)	fprintf(fptr, "\"%s %d %d\",\"%d\",\"0%d:0%d\",\"0%d:0%d\"", months[data[i].date.month], data[i].date.day, data[i].date.year, data[i].employeeID, data[i].startTime.hour, data[i].startTime.min, data[i].endTime.hour, data[i].endTime.min);
			else if (data[i].startTime.hour < 10 && data[i].startTime.min < 10 && data[i].endTime.hour > 10 && data[i].endTime.min < 10)	fprintf(fptr, "\"%s %d %d\",\"%d\",\"0%d:0%d\",\"%d:0%d\"", months[data[i].date.month], data[i].date.day, data[i].date.year, data[i].employeeID, data[i].startTime.hour, data[i].startTime.min, data[i].endTime.hour, data[i].endTime.min);
			else if (data[i].startTime.hour > 10 && data[i].startTime.min < 10 && data[i].endTime.hour > 10 && data[i].endTime.min < 10)	fprintf(fptr, "\"%s %d %d\",\"%d\",\"%d:0%d\",\"%d:0%d\"", months[data[i].date.month], data[i].date.day, data[i].date.year, data[i].employeeID, data[i].startTime.hour, data[i].startTime.min, data[i].endTime.hour, data[i].endTime.min);
			else if (data[i].startTime.hour > 10 && data[i].startTime.min < 10 && data[i].endTime.hour > 10 && data[i].endTime.min > 10)	fprintf(fptr, "\"%s %d %d\",\"%d\",\"%d:0%d\",\"%d:%d\"", months[data[i].date.month], data[i].date.day, data[i].date.year, data[i].employeeID, data[i].startTime.hour, data[i].startTime.min, data[i].endTime.hour, data[i].endTime.min);
			else if (data[i].startTime.hour > 10 && data[i].startTime.min > 10 && data[i].endTime.hour < 10 && data[i].endTime.min > 10)	fprintf(fptr, "\"%s %d %d\",\"%d\",\"%d:%d\",\"0%d:%d\"", months[data[i].date.month], data[i].date.day, data[i].date.year, data[i].employeeID, data[i].startTime.hour, data[i].startTime.min, data[i].endTime.hour, data[i].endTime.min);
			else if (data[i].startTime.hour > 10 && data[i].startTime.min > 10 && data[i].endTime.hour > 10 && data[i].endTime.min < 10)	fprintf(fptr, "\"%s %d %d\",\"%d\",\"%d:%d\",\"%d:0%d\"", months[data[i].date.month], data[i].date.day, data[i].date.year, data[i].employeeID, data[i].startTime.hour, data[i].startTime.min, data[i].endTime.hour, data[i].endTime.min);
			else fprintf(fptr, "\"%s %d %d\",\"%d\",\"%d:%d\",\"%d:%d\"", months[data[i].date.month], data[i].date.day, data[i].date.year, data[i].employeeID, data[i].startTime.hour, data[i].startTime.min, data[i].endTime.hour, data[i].endTime.min);
			//^covering the commmon options (for time... theere's 6 more option), should have used char time; over int hour, min;
		}

		closeFile(fptr);
	}

	//	/p	 print from file function
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

			for(i=0; i<12;i++){
				if (strcmp(months[i], token) == 0)
				{
					month = i+1;
				}
			}
				
			printf("Date : %d/", month);
			token = strtok(NULL, fileDelimiter);
			printf("%s/", token);
			token = strtok(NULL, fileDelimiter);
			printf("%s\t", token);
			token = strtok(NULL, fileDelimiter);
			printf("Employee ID : %s\t", token);
			token = strtok(NULL, fileDelimiter);
			printf("ClockIn time : %s\t", token);
			token = strtok(NULL, fileDelimiter);
			printf("ClockOut time : %s\n", token);
			token = strtok(NULL, fileDelimiter);

		}

	}

	//	/s	 search ID's from file funtion
	if (strcmp(argv[2], "/s") == 0)
	{
		FILE *fptr;
		char *fileName = argv[1], *mode = "r";
		fptr = openFile(fileName, mode);

		searchID = atoi(argv[3]);

		printf("\n");
		j = 0;

		while (!feof(fptr))
		{
			fgets(line, 50, fptr);
			len = strlen(line);
			token = strtok(line, fileDelimiter);
			for (i = 0; i<2; i++) {
				token = strtok(NULL, fileDelimiter);//skip to ID
			}
										 
			token = strtok(NULL, fileDelimiter);
			
			if (searchID == atoi(token))
			{
				if (j == 0) { 
					printf("\nResults of Employee ID Search\n");
				}
				
				fseek(fptr, -len, SEEK_CUR); //not perfect but works
				fgets(line, 50, fptr);
				
				token = strtok(line, fileDelimiter);
				for (i = 0; i<12; i++) {
					if (strcmp(months[i], token) == 0)
					{
						month = i + 1;
					}
				}
				printf("Date : %d/", month);
				token = strtok(NULL, fileDelimiter);
				printf("%s/", token);
				token = strtok(NULL, fileDelimiter);
				printf("%s\t", token);
				token = strtok(NULL, fileDelimiter);
				printf("Employee ID : %s\t", token);
				token = strtok(NULL, fileDelimiter);
				printf("ClockIn time : %s\t", token);
				token = strtok(NULL, fileDelimiter);
				printf("ClockOut time : %s\n", token);
				token = strtok(NULL, fileDelimiter);
				j=1;
			}
			if(j==0) {
				printf("No results found");
			}
		}
		closeFile(fptr);
	}
	return;
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