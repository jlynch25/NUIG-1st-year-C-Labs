#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main()
{
	 
	int i = 50;
	int *ptr1;
	int **ptr2;

	ptr1 = &i;
	ptr2 = &ptr1;

	printf("\nThe value of *ptr1 : %d", *ptr1);
	printf("\nThe value of **ptr2  : %d", **ptr2);

	return 0;

}