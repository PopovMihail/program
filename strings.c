#include <stdio.h>
#include <stdlib.h>

void sspn(char *s);
int slen(char *s);
int stok(char *str, char delim, char *ptr[]);	
int schr(char *str, char delim);
int sequal(char *s, char *s2);
void scopy(char *s, char *s2);
void suntok(char *str, char delim, char *ptr[], int cnt);
int raznica(char *s, char *s2);

int main()
{
	int i,j,k,f,f2,t,s,delta, d_str, j_sdvig, index;
	char dir1[] = "C:\\Windows";
	char dir2[] = "E:\\olololoXP";
	char del;
	char raz = '\\';
	char str[260] = "C:\\Windows\\system32+C:\\Use*r\\test+C:\\user\\explorer.exe+C:\\Windows\\Distrib";
	char *ptr[10];
	char *ptr_dir1[3];
	char *ptr_raz[6];
	printf("delim: ");
	scanf("%c",&del);
	char *suf = str;
//C:\\Windows\\system32+C:\\User\\test+C:\\user\\explorer.exe+C:\\Windows\\Distrib
/*	printf("paths: ");
	scanf("%c\n",&str);
	
	printf("dir1: ");
	scanf("%c\n",&dir1);
	printf("dir2: ");
	scanf("%c\n",&dir2);*/
	delta = raznica(dir1, dir2);
	d_str = slen(str);
	printf("n = %d\n", d_str);
	i = stok(str, del, ptr);
	k = stok(dir1, raz, ptr_dir1);
	//t = stok(ptr[0], raz, ptr_raz);
	
	
	
	
	for(j = 0;  j < i; j++) {
		sspn(ptr[j]);
	}
	
	for(j = 0;  j < i; j++) {
		t = stok(ptr[j], raz, ptr_raz);
		
		for(s = 0;  s < k; s++){
		
			f += sequal(ptr_raz[s], ptr_dir1[s]);
			//printf("F = %d\n", f);
			if((f == 2) ){
			
			index = ptr_raz[s+1] - suf;	
			printf("index= %d\n ", index);
			
			
			
			/*for(j_sdvig = d_str;  j_sdvig > index+2; j_sdvig--) {
				str[j_sdvig + delta] = str[j_sdvig];
			}*/
			ptr_raz[s + 1] = ptr_raz[s + 1] - delta;		
			suntok(ptr[j], raz, ptr_raz, t);
				
			
				
				
				
				
				scopy(dir2, ptr[j]);

			//	f = 0;
			}
			
			suntok(ptr[j], raz, ptr_raz, t);
		}
		f = 0;
	}
	
	suntok(str, del, ptr, i);
	printf("%s",str);
	
	return 0;
}
void sdvig(char *s, int delt, int idx)
{
	int i, n;
	char tmp;
	
	n = slen(s);
	if (delt > 0){
		for (i = idx; i < n ; i++)
			s[i-delt] = s[i]; 
	}
	if (delt < 0){
	
		for (i = n - delt; i > idx; i--){
		
			s[i] = s[i+delt];
		}
	}
}
int raznica(char *s, char *s2)
{
    int i;
    i = slen(s) - slen(s2);
     
    return i;
}
/*ЙНОХПНБЮМХЕ ЯРПНЙХ*/
void scopy(char *s, char *s2)
{
	int i;
	for(i = 0; (s[i] != '\0' && s2[i] != '\0'); i++)
		s2[i] = s[i];
	
}
/*ПЮГЛЕП ЯРПНЙХ*/
int slen(char *s)
{
    int i;
    for (i = 0; s[i] != '\0'; i++);
    return i;
}
/*ПЮГДЕКЕМХЕ МЮ ЯРНЙХ*/
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
/*ЯНАХПЮМХЕ ЯРПНЙХ*/
void suntok(char *str, char delim, char *ptr[], int cnt)
{
	int i;
	for(i = 1; i < cnt; i++){
		*(ptr[i] - 1) = delim;
	}
}
/*ОНХЯЙ ЯХЛБНКЮ Б ЯРПНЙЕ*/
int schr(char *str, char delim)
{
	int i, idx = -1;
	for(i = 0; (str[i] != '\0') && (str[i] != delim); i++);
		if(str[i] == delim)
			idx = i;
return idx;
}
/*ЯПЮБМЕМХЕ ЯРПНЙ*/ 
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
/*ОПНБЕПЙЮ МЮ ОПХМЮДКЕФМНЯРЭ ЯХЛБНКЮ ДЮММНЛС ЛМНФЕЯРБС*/

void sspn(char *s)
{
	int i;
	
	for(i = 0;  s[i] != '\0'; i++){
		if (s[i] ==  '*' ){
			
			fprintf(stderr, "invalid character number %d \n", i+1);
			printf("%s\n",s);
			//exit(EXIT_FAILURE);
		}
	}
}
