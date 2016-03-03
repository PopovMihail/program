#include <stdio.h>
#include <stdlib.h>

void sspn(char *s);
int slen(char *s);
int stok(char *str, char delim, char *ptr[]);	
int schr(char *str, char delim);
int sequal(char *s, char *s2);
void scopy(char *s, char *s2);
void suntok(char *str, char delim, char *ptr[], int cnt);

int main()
{
	int i,j,k,f,t;
	char dir1[] = "C:\\Windows";
	char dir2[] = "E:\\olololo";
	char del;
	char str[] = "C:\\Windows\\system32+C:\\Use*r\\test+C:\\*indows\\explorer.exe+C:\\Windows\\Distrib";
	char *ptr[10];
	printf("delim: ");
	scanf("%c",&del);
	
/*	printf("paths: ");
	scanf("%c\n",&str);
	
	printf("dir1: ");
	scanf("%c\n",&dir1);
	printf("dir2: ");
	scanf("%c\n",&dir2);*/
	
	i = stok(str, del, ptr);
	for(j = 0;  j < i; j++) {
		sspn(ptr[j]);
	}
	for(j = 0;  j < i; j++) {
		f = sequal(ptr[j], dir1);
		if(f == 1){
			scopy(dir2, ptr[j]);
		}
	}
	
	suntok(str, del, ptr, i);
	printf("%s",str);
	
	return 0;
}

/*копирование строки*/
void scopy(char *s, char *s2)
{
	int i;
	for(i = 0; (s[i] != '\0' && s2[i] != '\0'); i++)
		s2[i] = s[i];
	
}
/*размер строки*/
int slen(char *s)
{
    int i;
    for (i = 0; s[i] != '\0'; i++);
    return i;
}
/*разделение на стоки*/
int stok(char *str, char delim, char *ptr[])
{
	char *suf = str;
	ptr[0] = str; //   – "& str
	int i, j = 1; // j – '&&	% *1
	
	while( ( i = schr(suf, delim) ) >= 0 ){
		suf[i] = '\0';
		suf = suf + i + 1;
		ptr[j] = suf;
		j++;
	}
	
	return j;
}
/*собирание строки*/
void suntok(char *str, char delim, char *ptr[], int cnt)
{
	int i;
	for(i = 1; i < cnt; i++){
		*(ptr[i] - 1) = delim;
	}
}
/*поиск символа в строке*/
int schr(char *str, char delim)
{
	int i, idx = -1;
	for(i = 0; (str[i] != '\0') && (str[i] != delim); i++);
		if(str[i] == delim)
			idx = i;
return idx;
}
/*сравнение строк*/ 
int sequal(char *s, char *s2)
{
	
	int i, out = 1;
	
	for(i = 0; out && (s[i] != '\0' && s2[i] != '\0'); i++){
		if (s[i] != s2[i]){
			out = 0;
			return out;
		}
	}
	//out = 1;
	
	return out;
}
/*проверка на принадлежность символа данному множеству*/

void sspn(char *s)
{
	int i;
	
	for(i = 0;  s[i] != '\0'; i++){
		if (s[i] ==  '*' ){
			
			fprintf(stderr, "invalid character  %d \n", i);
			printf("%s\n",s);
			//exit(EXIT_FAILURE);
		}
	}
}
