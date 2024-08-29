#ifndef __WS13_H__
#define __WS13_H__

#define MAX_STR_LEN (20)
#define DEC (10)


char *Itoa(int num, char *nun_str);

int Atoi(char *nun_str);

char *ItoaAnyBase(int num, char *num_str, int base);

int AtoiAnyBase(char *num_str, int base);

void PrintChars(char *arr1, char *arr2, char *arr3, size_t arr1_len, size_t arr2_len, size_t arr3_len);

int IsLittleEndian();

#endif 
/*__WS13_H__*/
