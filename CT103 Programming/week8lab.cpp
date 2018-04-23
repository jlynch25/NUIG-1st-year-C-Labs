#include "stdafx.h"
#include <stdio.h>
#include "string.h"
#include "math.h"

int main()
{
	float ANS = 0;
	char Function[4];
	int Degree = 0;
	float RAD = 0;

	printf_s("Enter a trignomectic vaule e.g. 'cos'\n");
	gets_s(Function);
	if (Function == "cos", "sin", "tan", "sec", "cot", "csc")
	{
		printf_s("Enter the degree vaule e.g. '45'\n");
		scanf_s("%d", &Degree);
		RAD = Degree*(3.14159 / 180);


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

		printf_s("Answer %s(%d) = %.2f \n", Function, Degree, ANS);

		
		}
	else
		{
		printf_s("invalid trigonometric functions\n");
		}
	}
	
