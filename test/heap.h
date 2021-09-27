#include "ft_printf.h"
#define MAX_SIZE 10

typedef struct heap
{
    t_fp function[MAX_SIZE + 1];
    int size;
}   Heap;

void    Swap(t_fp *p, t_fp *c);
void    initializeHeap(Heap *heap);
void    Insert(Heap *heap, t_fp function);
t_fp    *Delete(Heap *heap);
