#include "psuedo_printf.h"
#define MAX_SIZE 100

typedef struct heap
{
    t_fp function[MAX_SIZE];
    int size;
}   Heap;

void    Swap(t_fp *p, t_fp *c);
void    initializeHeap(Heap *heap);
void    Insert(Heap *heap, t_fp function);
t_fp    *Delete(Heap *heap);
