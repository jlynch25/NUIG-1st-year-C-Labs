#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define X 400


int main(void)
{
	int array[26]= { 0 }, i,j,scale, num=0;
	char len[26], len1[40];
	srand(time(NULL));
	for (i = 0; i < X; ++i)
	{
		num = rand() % 26 + 97;
		j = num - 97;
		array[j]++;
		scale = j * 40;
	}
	int max = 0;
	max = array[0];
	for (int i = 0; i < 26; i++)
	{
		if (array[i] > max) max = array[i];
	}



	printf("number of throws = %d, max frequency = %d\n\n", X, max);
	for (i = 0, j=97; i < 26; ++i, ++j)
	{
		printf("	%c		%d		%.*s\n", j, array[i], scale,"*****************");
	}
	


	
}
