#include "stdafx.h"
#include <stdio.h>
#include <string.h>

void charAddresses(char *string); // 1st function to do
void commaToSpace(char *str); // 2nd function to do
void printWord(char *start); //3rd function to do
char *nextWord(char *start); // 4th function to do


void main()
{
	int i = 0;
	char location[200] = "7825,CREEK VALLEY,SACRAMENTO,95828,CA";
	char *ptr;

	// 1. call function to print out the address and content of each character in the input array
	charAddresses(location);

	// 2. call function to replace all the commas in the input string with tabs
	commaToSpace(location);

	puts("\nWithout commas:");
	puts(location);
	puts("");

	// 3. instead of printing characters (using putchar) until a '\0', printWord prints characters until a space ' '
	puts("First Word");
	printWord(location);

	puts("Second Word");
	printWord(location + 5);

	puts("Third Word");
	printWord(location + 11);
	puts("");

	// starting from the first character in the input string, each call to "nextWord" should return the next word in the string
	// e.g. if the input string is "Hi there everyone" :
	// first call to nextWord should return the address of the letter 't' of "there"
	// second call to nextWord should return the address of the first letter 'e'of "everyone"
	// third call to nextWord should return NULL
	ptr = location;
	while (ptr)
	{
		// instead of printing characters (using putchar) until a '\0', printWord prints characters until a space ' '
		printWord(ptr);
		printf("\n");
		ptr = nextWord(ptr);
	}


}

void charAddresses(char *string)
{
	// insert your code here
	int i, len;
	len = strlen(string);
	printf_s("address         Char\n");
	for (i = 0; i < len; i++)
	{
		printf_s("%p         %c\n", &string[i], string[i]);
	}
}
void commaToSpace(char *str)
{
	// insert your code here

	int p = 0, len;
	len = strlen(str);
	for (p = 0; p < len; p++)
	{
		if (str[p] != 44);
		else
		{
			str[p] = str[p] - 12;
		}
	}
}

void printWord(char *start)
{
	// insert your code here
	char *ptr;
	ptr = start;

	while (*ptr != 32)
	{
		putchar(*ptr);
		ptr++;
	}
	printf("\n");
}


char *nextWord(char *start)
{
	// insert your code here
	// of course it should only return NULL if there are no more words
	// HINT: 'return (start+i)' will return member [i] of the array (string) pointed at by 'start'
	int i = 1;
	char *ptr;
	ptr = start;
	
	if (start[i] == 32)
	{
		return (start+1);
	}
	do
	{
		i++;
		ptr++;
	}
	while (*ptr != 32);

	if (start[i+1] == '\0')
	{
		return NULL;
	}

}

