#include <stdio.h>
#include <stdlib.h>

	void stok(char *s);
	const int len = 25;
	const int size = 25;
	char ns[255][255];
	char del;

int main()
{
	int i,j;
	char p[3];//"C:\\Windows\\system32+C:\\User\\test+C:\\Windows\\explorer.exe+D:\\Windows\\Distrib";
	char dir1[255];
	char dir2[255];
	printf("delim: ");
	scanf("%c\n", &del);
	printf("paths: ");
	scanf("%c\n",&p);
	/*printf("dir1: ");
	scanf("%c\n",&dir1);
	printf("dir2: ");
	scanf("%c\n",&dir2);*/
	
	stok(p);
	
	for (i = 0; i < len; i++) {
		
		for(j = 0; j < size; j++){
			printf("%c", ns[i][j]);
			
		}	
	printf("\n");
	}
	/*char str[256] = "Hellow+world+*+I+KILL+YOU";
	char str2[256] = "Hellow+world+*+I+KILL+YOU";
	int i,j;
	//char delil;
	
	//sspn(str);
	//scanf("%c",&stk);
	printf("%d\n",scmp(str,str2));
	printf("%d\n",size_s(str));
	
	stok(str);
	
	for (i = 0; i < 25; i++) {
		
		for(j = 0; j < 25; j++){
			printf("%c", ns[i][j]);
			
		}	
	printf("\n");
	}
	//printf("%d\n",scmp(str,str2));	
	*/
    return 0;
}

/*размер строки*/
int size_s(char *s)
{
    int i;
    for (i = 0; s[i] != '\0'; i++);
    return i;
}
/*разделение на стоки*/
void stok(char *s)//, char stk)
{
	
	int i,j,k = 0;
	
    for (i = 0; i < len; i++) {
		
		for(j = k; s[j] != del; j++){
			if (s[j] == '\0'){
			break; 
			}
			
			ns[i][j - k] = s[j];
		}
		k = j + 1;
	}
	
}

/*сравнение строк*/ 
int scmp(char *s, char *s2)
{
	
	int i, k,out;
	k = size_s(s);
	if (k == size_s(s2)){
		for(i = 0; i < k; i++){
		if (s[i] != s2[i]){
			out = 1;
			return out;
		}
		}
	}
	out = 0;
	
	return out;
}
/*проверка на принадлежность символа данному множеству*/
/*
void sspn(char *s)
{
	int i, max;
	max = size_s(s);
	for(i = 0; i < max; i++){
		if (s[i] == '*' || '|' || '<' || '>' || '/' || '?' || ':'){
			fprintf(stderr, "invalid character | № %d \n", i);
			exit(EXIT_FAILURE);
		}
	}
	return 0;
}*/
