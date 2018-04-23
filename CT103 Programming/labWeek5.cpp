#include "stdafx.h"
#include "stdio.h"

void main()
{
	int i = 1;
	int noNumbers = 0;
	double number[100] ;
	double total = 0;
	double average = 0;
	double max = number[1];
	double Min = 0;
	
	printf("Wellcome to the average min and max calculater\n  how many numbers do you want to enter?\n");
	scanf_s("%d", &noNumbers);
	for (i = 0; i<noNumbers; i++)
	{
		printf("enter number  #%d ?\n ", i + 1);
		scanf_s("%lf", &number[i]);
		total += number[i];
		
		if (number[i] > max)
		{
			max = number[i];
		}
		if (i =0)
		{
			min = number[1];
		}
		if ( Min > number[i])
		{
			Min = number[i];
		}
	}
	average = total / (i);
	printf("Average of your numbers = %.2lf \n Your largest number = %.2f \n", average ,max);
	printf("Your smallest number = %.2lf \n", Min);

}