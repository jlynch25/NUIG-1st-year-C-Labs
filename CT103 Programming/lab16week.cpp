#include "stdafx.h"
#include <stdio.h>
#include "string.h"


FILE *openFile(char *fileName, char *mode);
void closeFile(FILE *fptr);


typedef struct
{
	int year;
	double tmax[12];
	int fakemonth[12];
	double tmin[12];
	int frostDays[12];
	double rain[12];
	double sun[12];
}data;

char months[12][10] = { "January","February","March","April","May","June","July","August","September","October","November","December" };

void main(void)
{
	data data[100];

	int i = 0, j = 0, mm = 1;
	char line[300];


	FILE *fptr;
	char fileName[] = "C:\\Users\\HP-\\Documents\\suttonboningtondata.txt";
	fptr = openFile(fileName, "r");

	//need to replace "---" and "Provisional" and "*" got stuck due to - also meaning minus ... so i just manually changed in file

	for (j = 0; j < 7; j++) fgets(line, 300, fptr);//skip opening text
	  

	while (!feof(fptr))
	{

		fgets(line, 300, fptr);
		sscanf(line, "%d %d %lf %lf %d %lf %lf", &data[i].year, &data[i].fakemonth[mm], &data[i].tmax[mm], &data[i].tmin[mm], &data[i].frostDays[mm], &data[i].rain[mm], &data[i].sun[mm]);
		//puts(line);
		//printf("%d %d %.2lf %.2lf %d %.2lf %.2lf\n", data[i].year, data[i].fakemonth[mm], data[i].tmax[mm], data[i].tmin[mm], data[i].frostDays[mm], data[i].rain[mm], data[i].sun[mm]);
		mm++;
		if (mm == 12) {
			i++;
		}

	}

	closeFile(fptr);


	double output = 0.0;
	int year = 0, month = 0;

	while (j != 0) {
		printf_s("Choose option:\n1: Temp Max\n2: Temp Min\n3: Air Frost Days Max\n4: Rain Max\n5: Sun Max\n0: Exit\n");
		scanf_s("%d", &j);

		switch (j) {
			
		case 1 :{
			for (i = 0; i < 100; i++)
			{
				for (j = 0; j < 12; j++)
				{
					if (data[i].tmax[j] > output)
					{
						year = i;
						month = j+1;
						output = data[i].tmax[j];
					}
				}
			}
			printf("The maxmium tempature was in %s of %d with %.1lf degrees C \n\n", months[month], year + 1959, output);
			output = 0.0;
			break;
			}
		case 2: {
			for (i = 0; i < 100; i++)
			{
				for (j = 0; j < 12; j++)
				{
					if (data[i].tmin[j] < output)
					{
						year = i;
						month = j+1;
						output = data[i].tmin[j];
					}
				}
			}
			printf("The minmium tempature was in %s of %d with %.1lf degrees C \n\n", months[month], year + 1959, output);
			output = 0.0;
			break;

		}
		case 3: {
			for (i = 0; i < 100; i++)
			{
				for (j = 0; j < 12; j++)
				{
					if (data[i].frostDays[j] > output)
					{
						year = i;
						month = j+1;
						output = data[i].frostDays[j];
					}
				}
			}
			printf("The month with the most Frost days was %s of %d with %.0lf days \n\n", months[month], year + 1959, output);
			output = 0.0;
			break;

		}
		case 4: {
			for (i = 0; i < 100; i++)
			{
				for (j = 0; j < 12; j++)
				{
					if (data[i].rain[j] > output)
					{
						year = i;
						month = j+1;
						output = data[i].rain[j];
					}
				}
			}
			printf("Wettest month was %s of %d with %.1lfmm rainfall \n\n", months[month], year + 1959, output);
			output = 0.0;
			break;

		}
		case 5: {
			for (i = 0; i < 100; i++)
			{
				for (j = 0; j < 12; j++)
				{
					if (data[i].sun[j] > output)
					{
						year = i;
						month = j+1;
						output = data[i].sun[j];
					}
				}
			}
			printf("Sunnyest month was %s of %d with %.1lf hours of sun \n\n", months[month], year + 1959, output);
			output = 0.0;
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
