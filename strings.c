#include <stdio.h>
#include <stdlib.h>



int main()
{
	
	char str[256] = "Hellow world * I KILL YOU";
	int i,j;
	sspn(str);
	printf("%d\n",size_s(str));
	
	stok(str, ' ');
	
	
    return 0;
}

/*ðàçìåð ñòðîêè*/
int size_s(char *s)
{
    int i;
    for (i = 0; s[i] != '\0'; i++);
    return i;
}
/*ðàçäåëåíèå íà ñòîêè*/
void stok(char *s, char stk)
{

	int i,j,k = 0;
	int len = 25;
	int	size = 25;
	char ns[len][size];
	
	if (stk != ' ')
	{
		fprintf(stderr, "wrong separator \n");
    	exit(EXIT_FAILURE);
	}
	
		
	
    for (i = 0; i < len; i++) {
		for(j = k; s[j] != stk ; j++){
			if (s[j] == '\0'){
			//printf("\nline end");
			exit (0);
			}
			ns[i][j] = s[j];
			printf("%c", ns[i][j]);
			//return ns[i][j];
		}	
		k = j+1;
		printf("\n");
	}
//	return 0;
}
/*ïðîâåðêà íà ïðèíàäëåæíîñòü ñèìâîëà äàííîìó ìíîæåñòâó*/
void sspn(char *s)
{
	int i, max;
	max = size_s(s);
	for(i = 0; i < max; i++){
		if (s[i] == '*' || '|' || '<' || '>' || '/' || '?' || ':'){
			fprintf(stderr, "invalid character | ¹ %d \n", i);
			exit(EXIT_FAILURE);
		}
	}
	return 0;
}
