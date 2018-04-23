#include "stdafx.h"
#include <stdio.h>
#include "string.h"
#include <math.h>

int main()
{
	float ANS = 0;
	char Function[4];
	char Angle;
	char Loop;
	int Degree = 0, RAD = 0;

	printf_s("Enter a trigonometric vaule e.g. 'cos'\n");
	gets_s(Function);


	printf_s("whould you like to use Degrees or Radians?\nType 'd' for Degrees or 'r' for Radians\n ");
	scanf_s("%c", &Angle);
	if (Angle == 'd')
	{
		printf_s("Enter the degree vaule e.g. '45'\n");
		scanf_s("%d", &Degree);
		RAD = Degree*(3.14159 / 180);
	}
	else
	{
		printf_s("Enter the Radian value e.g. '2'\n");
		scanf_s("%d", &RAD);
	}

	if (!strcmp("cos", Function))
	{
		ANS = cos(RAD);
	}
	else if (!strcmp("sin", Function))
	{
		ANS = sin(RAD);
	}
	else if (!strcmp("tan", Function))
	{
		ANS = tan(RAD);
	}
	else if (!strcmp("sec", Function))
	{
		ANS = 1 / (cos(RAD));
	}
	else if (!strcmp("cot", Function))
	{
		ANS = 1 / (tan(RAD));
	}
	else if (!strcmp("csc", Function))
	{
		ANS = 1 / (sin(RAD));
	}
	else
	{
		printf_s("invalid trigonometric function\n");
		printf("whould you like to enter another trigonometric function? y/n \n");
		scanf_s("%c", &Loop);
		if (Loop == 'y')
		{
			main();
		}
		else
		{
			printf_s("Thank you using the trigonometric calculater, Goodbye");
		}
	}

	if (Angle == 'd')
	{
		printf_s("Result %s(%d) = %.2f \n", Function, Degree, ANS);
	}
	else
	{
		printf_s("Result %s(%d) = %.2f \n", Function, RAD, ANS);
	}

	printf("whould you like to enter another trigonometric function? y/n \n");
	
	scanf_s("%c", &Loop);
	
		if (Loop == 'y')
		{
		main();
		}
		else
		{ 
		printf_s("Thank you using the trigonometric calculater, Goodbye");
		}


}