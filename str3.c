#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "proc.h"

int main()
{
	char str[261] ;
	char *ptr[20];
	
	input(str);
	check(str);
	process(str, ptr);
	return 0;
}

