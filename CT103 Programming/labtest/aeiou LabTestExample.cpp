#include <stdio.h>
#include "stdafx.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// A E I O U
int function(char*);

int main() {

	printf("%d", function("Odc t a ;.,][/A"));
	return 0;
}

int function(char*string) {

	int i = 0, len, count =0;
	len = strlen(string);
	for (i = 0; i < len; i++) {
	

		if (tolower(string[i]) == 'a' || tolower(string[i]) == 'e' || tolower(string[i]) == 'i' || tolower(string[i]) == 'o' || tolower(string[i]) == 'u')
		{
			count++;
		}
	}
	return count;
}

