
#include "stdio.h"


void main()
{
	int hoursWorked = 0;
	float basicRate = 12.5;
	float overTimeRate = basicRate * 2;
	float pay = 0.0;

	printf("Enter hours worked: ");
	scanf_s("%d", &hoursWorked);
	if (hoursWorked <= 40)
	{
		pay = hoursWorked*basicRate;
	}
	else(pay = 40 * basicRate + (hoursWorked - 40)*overTimeRate);


	printf("You have worked %d hours, and earned %.2f \n", hoursWorked, pay);
}
