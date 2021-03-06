#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>


#define PI 3.14159
#define CIRC(r) ( PI*((r)*(r)))



typedef enum  { DRY, SHOWERS, RAIN, FOGGY, SNOW, SLEET }precipitation;
char  weather[6][30] = { "DRY", "SHOWERS", "RAIN", "FOGGY", "SNOW", "SLEET" };

precipitation getRandPrecip();
char *getPrecipString(precipitation p);
FILE *openFile(char *fileName, char *mode);
void closeFile(FILE *fptr);
double getAverageBalance(char *filePath);
double compoundInterest(double loan, int years, double rate);
bool checkSpelling(char *word);

void main() {


	double circ = CIRC(2.0);
	printf("circumference = %.2lf \n", circ);


	precipitation p = getRandPrecip();
	puts(getPrecipString(p));


	double averageBalance = getAverageBalance("C:\\Users\\HP-\\Documents\\bank.csv");
	printf("Average Balance of Customers = %.2lf \n", averageBalance);
	
	bool result = checkSpelling("word");
	printf("%d\n", result);

	double interest = compoundInterest(10000.00, 15, 0.08);
	printf("interest = %.2lf\n", interest);
	
}

char *getPrecipString(precipitation p) {

	char *ptr = (char*)malloc(sizeof(char) * 10);
	ptr = weather[p];
	return ptr;
}


precipitation getRandPrecip() {
	
	precipitation random;

	srand(time(NULL));
	//random = rand() % 6 + 0; // error 
	return random;
}

double getAverageBalance(char *filePath) {

	int i = 0, j = 0, bal[4500], avg = 0;
	char line[550];
	char delimiter[10] = ",";
	char *token;

	FILE *fptr;
	fptr = openFile(filePath, "r");

	for (j = 0; j < 1; j++) fgets(line, 550, fptr);

	while (!feof(fptr))
	{
		fgets(line, 550, fptr);

		token = strtok(line, delimiter);

		for (j = 0; j < 7; j++) {
			token = strtok(NULL, delimiter);
		}
		bal[i] = atof(token);
		i++;
	}
	closeFile(fptr);
	for (j = 0; j < i; j++) {
		avg += bal[j];
	}
	avg = (avg / i);

	return avg;
}

bool checkSpelling(char *word) {
	char line[50], *token;
	int i = 0;
	char delimiter[10] = "\n";
	FILE *fptr;
	char fileName[] = "C:\\Users\\HP-\\Documents\\webster.txt";
	fptr = openFile(fileName, "r");

	while (!feof(fptr))
	{
		fgets(line, 50, fptr);

		token = strtok(line, delimiter);

		if (strcmp(word, token)) {
			i = 1;
			break;
		}
	}
	closeFile(fptr);
	return i;
}


double compoundInterest(double loan, int years, double rate) {
	int i = 0;
	float result = 0.0;
	double preyear = 0.0;

	for (i = 0; i < years; i++)
	{
		if (i == 0) {
			preyear = loan;
		}



		result = (preyear*rate) + preyear;

		preyear = result;

	}
	result = result - loan; //insteal loan

	return result;
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