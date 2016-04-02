#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "proc.h"

void input(char *s)
{
	printf("Please input string \n");
	//scanf("%s", &s);
	int i=0;
	do{
		scanf("%c",&s[i]); i++;
	}while(s[i-1] != '\n');
	s[i-1] = '\0';
}

void check(char *s)
{
	sspn(s);
}

void process(char *str, char *ptr[])
{
	int i=0, t, f, max;
	//char del;
	char win = '\\';
	char lin = '/';
	
	if (schr(str, win) == -1) {
		printf("OS: Linux\n");
		t = stok(str, lin, ptr);
		printf("Depth: %d\n", t-2);
		
		max = slen(ptr[i]);
	
		for (i = 0; i < t-1; i++) {
			if (slen(ptr[i]) > max)
				max = slen(ptr[i]);
		}
		printf("Max dir name: ");
		for (i = 0; i < t-1; i++) {
			if(slen(ptr[i]) == max){
				printf("%s, ",ptr[i] );
			}
		}
	suntok(str, lin, ptr, t);
	}
	else{
	
	if (schr(str, lin) == -1) {
		t = schr(str, ':');
		//printf("t = %d\n, ", t );
		if ((t <= 3) && (t > 0)){
			for (i = 0; i < t; i++){
				f = isCase(str[i]);
				//printf("f = %d\n, ", f );
				if (f == 0){
					printf("Invalid put ");
					exit(EXIT_FAILURE);
				}
					
			}
			if ( str[t + 1] == win) {
				printf("OS: Windows\n");
				t = stok(str, win, ptr);
				printf("Depth: %d\n", t-2);
				
				max = slen(ptr[i]);
			
				for (i = 0; i < t-1; i++) {
					if (slen(ptr[i]) > max)
						max = slen(ptr[i]);
				}
				printf("Max dir name: ");
				for (i = 0; i < t-1; i++) {
					if(slen(ptr[i]) == max){
						printf("%s, ",ptr[i] );
					}
				}
				suntok(str, lin, ptr, t);
				
			}
		}
		else{
		printf("Invalid put ");
		}
	} 
		
	}
}
