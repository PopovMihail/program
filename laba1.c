#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int schr(char str[], char delim);
int stok(char str[], char delim, char *ptr[]);
int main()
{
	int i;
	char ch[260]; // vremenniy massiv dlya dannih
	char delim; // razdelitel'
	char ptr[20];
	
    printf("Vvedite razdlitel':\n");
      scanf("%c", &delim); // razdelitel'
          printf("Vvedite imya polzovatelya:\n");
      scanf("%s", &ch);
       char *username = (int *)malloc(size_s(ch)*sizeof(int)); // imya polzovatelya
        for (i=0; i<size_s(ch); i++)
         username[i]=ch[i];
    printf("Vvedite imya domashney direktorii:\n");
      scanf("%s", &ch);
       char *dir = (int *)malloc(size_s(ch)*sizeof(int)); // imya domashnego kataloga
        for (i=0; i<size_s(ch); i++)
         dir[i]=ch[i];
    printf("Vvedite puti cherez razdeliteli:\n");
      scanf("%s", &ch);
       char *paths = (int *)malloc(size_s(ch)*sizeof(int)); // vhodnaya stroka s putyami
        for (i=0; i<size_s(ch); i++)
         paths[i]=ch[i];
    
    //printf("Vvedeno:\n%c\n%s\n%s\n%s\n", delim, username, dir, paths);
    
	stok(paths, delim,ptr);	// zanosim puti v noviy massiv 
	printf("%s", ptr);
	//sspn(paths);
    return 0;
}

// dinamicheskoe zapolnenie massiva
/*int lenMas(char s[], char m[])
{
	int i;
	s = (int *)malloc(size_s(m)*sizeof(int));
	for (i=0; i<size_s(m); i++)
         s[i]=m[i];
}*/

// ðàçìåð ñòðîêè
int size_s(char *s)
{
    int i;
    for (i = 0; s[i] != '\0'; i++);
    return i;
}

// ðàçäåëåíèå íà ñòîêè
int stok(char str[], char delim, char *ptr[])
{
char *suf = str;
ptr[0] = str; // первое поле – начало str
int i, j = 1; // j – счетчик полей
while( ( i = schr(suf, delim) ) >= 0 ){
suf[i] = '\0';
suf = suf + i + 1;
ptr[j] = suf;
j++;
printf("ptr = %c", ptr[2]);
}
return j;
}

int schr(char str[], char delim)
{
	int i, idx = -1;
	for(i = 0; (str[i] != '\0') &&(str[i] != delim); i++)
		if(str[i] == delim)
		idx = i;


return idx;
}

// ïðîâåðêà íà ïðèíàäëåæíîñòü ñèìâîëà äàííîìó ìíîæåñòâó
void sspn(char *s)
{
	int i, max;
	max = size_s(s);
	for(i = 0; i < max; i++){
		if (s[i] == '*' /*|| '|' || '<' || '>' || '/' || '?' || ':'*/ ){
			fprintf(stderr, "zapreshenniy simvol na pozicii %d \n", i);
			exit(EXIT_FAILURE);
		}
	}
	return 0;
}
