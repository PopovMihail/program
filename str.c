#include <stdio.h>
#include <stdlib.h>


void sspn(char *s);
int slen(char *s);
int stok(char *str, char delim, char *ptr[]);	
int schr(char *str, char delim);
int sequal(char *s, char *s2);
void scopy(char *s, char *s2);
void suntok(char *str, char delim, char *ptr[], int cnt);
int isCase(char ch);

int main()
{
	int i, t, k, f, max;
	char del;
	char win = '\\';
	char lin = '/';
	char str[260] = "s:\\home\\qwert\\sandbox\\openmpi\\1.6.5\\lib\\OpenMPI\\mca_btl_tcp.so ";
	char *ptr[20];
	
	
	if (schr(str, win) == -1) {
		printf("OS: Linux\n");
		t = stok(str, lin, ptr);
		printf("Depth: %d\n", t-1);
		
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
	//suntok(str, del, ptr, i);
	//printf("%s",str);
	
	return 0;
}

int isCase(char ch)
{
	//int i;
	//for (i = 0; ch != '\0'; i++){
		if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
			return 1;
	//}
return 0;
}

 //определение длинны строки
int slen(char *s)
{
    int i;
    for (i = 0; s[i] != '\0'; i++);
    return i;
}
///*разбиение строки на подстроки
int stok(char *str, char delim, char *ptr[])
{
	char *suf = str;
	ptr[0] = str; // 
	int i, j = 1; // 
	
	while( ( i = schr(suf, delim) ) >= 0 ){
		suf[i] = '\0';
		suf = suf + i + 1;
		ptr[j] = suf;
		j++;
	}
	
	return j;
}
//*собирание подстрок в исходную строку
void suntok(char *str, char delim, char *ptr[], int cnt)
{
	int i;
	for(i = 1; i < cnt; i++){
		*(ptr[i] - 1) = delim;
	}
}
//*поиск символа в строке
int schr(char *str, char delim)
{
	int i, idx = -1;
	for(i = 0; (str[i] != '\0') && (str[i] != delim); i++);
		if(str[i] == delim)
			idx = i;
return idx;
}
//*сравнение двух строк
int sequal(char *s, char *s2)
{
	int i, out = 1;
	
	for (i = 0; out && (s[i] != '\0' && s2[i] != '\0'); i++) {
		if (s[i] != s2[i]) {
			out = 0;
			return out;
		}
	}
	//out = 1;
	
	return out;
}
//*проверка строки на не допустимые символы

void sspn(char *s)
{
	int i;
	
	for(i = 0;  s[i] != '\0'; i++){
		if ((s[i] == '*') || (s[i] == '?') || (s[i] == '"') || (s[i] == '>') || (s[i] == '<') || (s[i] == '|') ){
			
			fprintf(stderr, "invalid character number %d \n", i+1);
			printf("%s\n",s);
			//exit(EXIT_FAILURE);
		}
	}
}
