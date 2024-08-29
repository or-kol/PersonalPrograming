#ifndef __WS10_H__
#define __WS10_H__

enum status {REALLOC_ERROR = -2, MALLOC_ERROR, SUCCESS};

typedef struct funcs funcs_t;

typedef struct element
{
	void *data;
	funcs_t *funcs;
} element_t;

typedef int(*Add_t)(element_t *, int);
typedef void(*Print_t)(element_t *);
typedef void(*Clean_t)(element_t *);

struct funcs
{
	Add_t add;
	Print_t print;
	Clean_t clean;
};

void InitInt(int x, element_t *arr);
void InitFloat(float x, element_t *arr);
int InitString(char *x, element_t *arr);

void PrintAll(element_t *arr, int num_of_elements);
int AddAll(element_t *arr, int num_of_elements, int to_add); 
void CleanAll(element_t *arr, int num_of_elements); 

#endif 
/* __WS10_H__ */
