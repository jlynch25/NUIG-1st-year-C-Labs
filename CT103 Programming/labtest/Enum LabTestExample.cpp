#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

typedef enum { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday } daysOfTheWeek;
char  dayWeek[7][30] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

char* function(daysOfTheWeek);

void main() {

	printf("%s ", function(Friday));
}

char* function(daysOfTheWeek day) {

	char *ptr = (char*)malloc(sizeof(char) * 10);
	ptr = dayWeek[day];
	return ptr;
}
