#include "LZSS.h"

int main ( int argc, char *argv [])
{
	setlocale(LC_ALL, "Russian");

	//архивация
	BFILE *coutput;
	FILE  *cinput;

	//разархивация
	BFILE *dinput;
	FILE  *doutput;

	setbuf(stdout, NULL);
	
	if (argc != 5){
		 fatal_error ( "неверно набранна команда\n");
	}
		
	if (strcmp(argv[1], "-c") == 0 && strcmp(argv[2], "-o") == 0) { 
		
		coutput = OpenOutputBFILE (argv [3]);
		  
		if (coutput == NULL)
			fatal_error ( "ошибка при открытии файла %s	для вывода\n", argv [3]);
			
		cinput = fopen ( argv [4], "rb");
		
		if (cinput == NULL)
			fatal_error ( "ошибка при открытии файла %s для ввода\n", argv [4]); 
		
		printf ( "\nсжимаю %s в %s\n", argv [4], argv [3]);
		
		CompressFile (cinput, coutput);
		CloseOutputBFile (coutput);
		fclose (cinput);
		print_ratios (argv[4], argv[3]);	
	} else 
		
		if (strcmp(argv[1], "-d") == 0 && strcmp(argv[2], "-o") == 0) { 
			 
			doutput = fopen ( argv [3], "wb");
	  
			if (doutput == NULL)
				fatal_error ( "ошибка при открытии файла %s для вывода\n", argv [3]);
						
			dinput = OpenInputBFile (argv [4]);
			
			if (dinput == NULL)
				 fatal_error ( "?ошибка при открытии файла %s\
					для ввода\n", argv [4]); 
			
			
				printf ( "\nразархивирую %s в %s\n", argv [4], argv [3]);
				
				
			ExpandFile (dinput, doutput);
			CloseInputBFile (dinput);
			fclose (doutput);
			print_ratios ( argv [4], argv [3]);
		}


	return 0;
}
