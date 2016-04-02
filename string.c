#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int isCase(char ch)
{
	//int i;
	//for (i = 0; ch != '\0'; i++){
		if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
			return 1;
	//}
return 0;
}

 //îïðåäåëåíèå äëèííû ñòðîêè
int slen(char *s)
{
    int i;
    for (i = 0; s[i] != '\0'; i++);
    return i;
}
///*ðàçáèåíèå ñòðîêè íà ïîäñòðîêè
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
//*ñîáèðàíèå ïîäñòðîê â èñõîäíóþ ñòðîêó
void suntok(char *str, char delim, char *ptr[], int cnt)
{
	int i;
	for(i = 1; i < cnt; i++){
		*(ptr[i] - 1) = delim;
	}
}
//*ïîèñê ñèìâîëà â ñòðîêå
int schr(char *str, char delim)
{
	int i, idx = -1;
	for(i = 0; (str[i] != '\0') && (str[i] != delim); i++);
		if(str[i] == delim)
			idx = i;
return idx;
}
//*ñðàâíåíèå äâóõ ñòðîê
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
//*ïðîâåðêà ñòðîêè íà íå äîïóñòèìûå ñèìâîëû

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
