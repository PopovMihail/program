#ifndef LZSS
#define LZSS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>


typedef unsigned char uchar;
typedef unsigned long ulong;

//char *CompressionName = "Кодер LZSS";
//char *Usage = "входной_файл выходной_файл\n\n"; 



//----------------------------------------------------------------------------
//Побитовый доступ к файлам

typedef struct bfile
{
  FILE *file;
  uchar mask;
  int rack;
  int pacifier_counter;
}
BFILE;

#define PACIFIER_COUNT 2047

BFILE *OpenInputBFile ( char *name);
BFILE *OpenOutputBFile ( char *name);
void  WriteBit ( BFILE *bfile, int bit);
void  WriteBits ( BFILE *bfile, ulong code, int count);
int   ReadBit ( BFILE *bfile);
ulong ReadBits ( BFILE *bfile, int bit_count);
void  CloseInputBFile ( BFILE *bfile);
void  CloseOutputBFile ( BFILE *bfile);

//----------------------------------------------------------------------------
// Функции высокого уровня

void CompressFile ( FILE *input, BFILE *output);
void ExpandFile ( BFILE *input, FILE *output);
void usage_exit ( char *prog_name);
void print_ratios ( char *input, char *output);
long file_size ( char *name);


//----------------------------------------------------------------------------
// Функции работы с моделью данных для алгоритма LZSS
void InitTree ( int r);
void ContractNode ( int old_node, int new_node);
void ReplaceNode ( int old_node, int new_node);
int  FindNextNode ( int node);
void DeleteString ( int p);
int  AddString ( int new_node, int *match_position);


//----------------------------------------------------------------------------
// Константы, используемые при работе LZSS

// Количество битов в коде, содержащих смещение совпадения
#define INDEX_BITS  12
// Количество битов в коде, содержащих длину совпадения
#define LENGTH_BITS  4
// Длина скользящего окна в байтах
#define WINDOW_SIZE  ( 1 << INDEX_BITS)  //4096 при INDEX_BITS = 12 

// Максимальная длина совпадения
#define RAW_LOOK_AHEAD_SIZE ( 1 << LENGTH_BITS)
// Константа, определяющая способ кодирования
#define BREAK_EVEN (( 1 + INDEX_BITS + LENGTH_BITS) / 9)
// Максимальная длина совпадения с учетом того, что длины
// 0 и 1 не используются
#define LOOK_AHEAD_SIZE ( RAW_LOOK_AHEAD_SIZE + BREAK_EVEN)
// Определяющий узел - корень двоичного дерева
#define TREE_ROOT WINDOW_SIZE
// Специальный индикатор конца файла
#define END_OF_STREAM 0
// Специальный номер узла
#define UNUSED 0
// Макро, выполняющее преобразование индекса при работе с
// кольцевым буфером
#define MODULO(a)  ( (a) & (WINDOW_SIZE - 1) )

//char *CompressionName = "Кодер LZSS";
//char *Usage = "входной_файл выходной_файл\n\n"; 

#endif
