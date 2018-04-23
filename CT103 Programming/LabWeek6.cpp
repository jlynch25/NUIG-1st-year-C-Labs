#include "stdafx.h"
#include <stdio.h>

void main()
{
	int i = 0;    // for the 1st output line
	int ii = 0;   // for the 2nd output line
	int iii = 0;  // for the 3rd output line
	int p = 0;    // for the  2nd & 3rd output line
	

	int array[] = { 65,116,32,50,48,32,68,101,103,114,101,101,115,44,32,84,104,101,32,87,101,97,116,104,101,114,32,73,115,32,71,114,101,97,116,46 };

	// for the 1st output line
	i = 0;
	do
	{
		printf("%c", array[i]);
		i++;
	} while (array[i] != 46);
	printf("\n\n");


	// for the 2nd output line
	for (p = 0; array[p] != 46; p++)
	{
		if (array[p] < 97); //does nothing
		else
		{
			array[p] = array[p] - 32;
		}
	}

	ii = 0;
	do
	{
		printf("%c", array[ii]);
		ii++;
	} while (array[ii] != 46);
	printf("\n\n");

	p = 0;

	// for the 3rd output line
	for (p = 0; array[p] != 46; p++)
	{
		if (array[p] >= 97 || array[p] < 65);  //does nothing
		else
		{
			array[p] = array[p] + 32;
		}
	}

	iii = 0;
	do
	{
		printf("%c", array[iii]);
		iii++;
	} while (array[iii] != 46);
	printf("\n\n");
}
