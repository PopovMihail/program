#include <stdio.h>
#include <stdlib.h>


void sspn(char *s);
int slen(char *s);
int stok(char *str, char delim, char *ptr[]);	
int schr(char *str, char delim);
int sequal(char *s, char *s2);
void scopy(char *s, char *s2);
void suntok(char *str, char delim, char *ptr[], int cnt);
void shift(char *ptr, char *ptr2, char *str, int lengs, int idx, int delta, int s, int j);

int main()
{
	int i,j,k,t,s,delta, d_str, j_sdvig, index;
	char dir1[15] = "win";
	char dir2[15] = "winXP";
	char del;
	char raz = '\\';
	char str[260] = "C:\\win\\explorer.exe+C:\\Wpn\\sys\\tem32+C:\\win\\Distrib";
	char *ptr[10];
	char *ptr_dir1[10];
	char *ptr_raz[10];
	printf("delim: ");
	scanf("%c",&del);
	char *suf = str;
//C:\\Windows\\system32+C:\\User\\test+C:\\user\\explorer.exe+C:\\Windows\\Distrib
/*	printf("paths: ");
	scanf("%s",&str);
		
	printf("dir1: ");
	scanf("%s",&dir1);
	
	printf("dir2: ");
	scanf("%s",&dir2);*/
	
	delta = slen(dir1) - slen(dir2);
	d_str = slen(str);
	//printf("delta = %d\n", delta);
	i = stok(str, del, ptr);
	k = stok(dir1, raz, ptr_dir1);
	//t = stok(ptr[0], raz, ptr_raz);
	//printf("k = %d\n", k);
	
	int f = 0;
	
	
	for(j = 0;  j < i; j++) {
		sspn(ptr[j]);
	}
	
	for (j = 0;  j < i; j++) {
		t = stok(ptr[j], raz, ptr_raz);
		if(k > 1){
		for (s = 0;  s < k; s++) {
			f += sequal(ptr_dir1[s], ptr_raz[s]);
			if (f == k) {
				index = ptr_raz[s+1] - suf;	
				if (delta < 0) {
					for (j_sdvig = d_str - delta;  j_sdvig > index + delta; j_sdvig--) {
						str[j_sdvig - delta] = str[j_sdvig];
					}
					
					for (j_sdvig = j;  j_sdvig < i; j_sdvig++) {
						ptr[j_sdvig + 1] = ptr[j_sdvig + 1] - delta;
					}
					ptr_raz[s +1] = ptr_raz[s + 1] - delta;		
				}
				
				if (delta > 0) {
					//d_str = d_str - delta;
					for (j_sdvig = index;  j_sdvig < d_str; j_sdvig++) {
						str[j_sdvig - delta] = str[j_sdvig];
					}
					str[d_str-delta] = '\0';
					for (j_sdvig = j;  j_sdvig < i; j_sdvig++) {
						ptr[j_sdvig + 1] = ptr[j_sdvig + 1] - delta;
					}
					ptr_raz[s + 1] = ptr_raz[s + 1] - delta;		
				}
							//shift(*ptr, *ptr_raz, str, d_str, index, delta, s, j);
				suntok(ptr[j], raz, ptr_raz, t);
				scopy(dir2, ptr[j]);	
				f = 0;
			}
			
			suntok(ptr[j], raz, ptr_raz, t);
		}
		
		}
		
		for (s = 0;  s < t; s++) {
			f += sequal(dir1, ptr_raz[s]);
			//printf("f = %d\n", f);
			if(f == 1){
				//printf("s = %d\n", s);
				index = ptr_raz[s+1] - suf;	
				///printf("index= %d\n ", index);
						
				if (delta < 0) {
					for (j_sdvig = d_str - delta;  j_sdvig > index + delta; j_sdvig--) {
						str[j_sdvig - delta] = str[j_sdvig];
					}
					
					for (j_sdvig = j;  j_sdvig < i; j_sdvig++) {
						ptr[j_sdvig + 1] = ptr[j_sdvig + 1] - delta;
					}
					
					ptr_raz[s + 1] = ptr_raz[s + 1] - delta;		
				}
				
				if (delta > 0) {
					for (j_sdvig = index;  j_sdvig < d_str; j_sdvig++) {
						str[j_sdvig - delta] = str[j_sdvig];
					}
					str[d_str-delta] = '\0';
					for (j_sdvig = j;  j_sdvig < i; j_sdvig++) {
						ptr[j_sdvig + 1] = ptr[j_sdvig + 1] - delta;
					}
					ptr_raz[s + 1] = ptr_raz[s + 1] - delta;
				}
				scopy(dir2, ptr_raz[s]);
			f = 0;			
			}
			suntok(ptr[j], raz, ptr_raz, t);
		}
		
		//f = 0;
	}
	
	suntok(str, del, ptr, i);
	printf("%s",str);
	
	return 0;
}
/*
void shift(char *ptr, char *ptr2, char *str, int lengs, int idx, int delta, int s, int j)
{
	int i;
	if (delta < 0) {
		for (i = lengs - delta; i > idx + delta; i--) {
			str[i - delta] = str[i];
		}
					
		for (i = j;  i < i; i++) {
			ptr[i + 1] = ptr[i + 1] - delta;
		}					
		ptr2[s + 1] = ptr2[s + 1] - delta;		
	}
				
	if (delta > 0) {
		for (i = idx;  i < lengs; i++) {
			str[i - delta] = str[i];
		}
		str[lengs-delta] = '\0';
		for (i = j;  i < i; i++) {
			ptr[i + 1] = ptr[i + 1] - delta;
		}
		ptr2[s + 1] = ptr2[s + 1] - delta;		
	}
}
*/

 //копирование строк
void scopy(char *s, char *s2)
{
	int i;
	for(i = 0; (s[i] != '\0' && s2[i] != '\0'); i++)
		s2[i] = s[i];
	
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
