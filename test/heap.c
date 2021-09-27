#include "psuedo_printf.h"
#include "heap.h"

void    Swap(t_fp *p, t_fp *c)
{
    t_fp tmp;

    tmp = *p;
    *p = *c;
    *c = tmp;
}

void    initializeHeap(Heap *heap)
{
    for (int i = 0; i < MAX_SIZE; i++)
	{
		heap->function[i].print = 0;
		heap->function[i].print_l = 0;
		heap->function[i].print_untyped = 0;
		heap->function[i].priority = 0;
	}
	heap->size = 0;
}

void    Insert(Heap *heap, t_fp function)
{
    int index;

    heap->size += 1;
    index = heap->size;
    while (index != 1 && function.priority < heap->function[index / 2].priority)
    {
        heap->function[index] = heap->function[index / 2];
        index /= 2;
    }
    heap->function[index] = function;
}

t_fp	*makeRoot()
{
	t_fp *root;

	root = (t_fp *)malloc(sizeof(t_fp));
	if (root == 0)
		return (0);
	return (root);
}

t_fp    *Delete(Heap *heap)
{
    t_fp *root;
    int parent;
    int child;

	root = 0;
    parent = 1;
    if (heap->size == 0)
        return (root);
	root = makeRoot();
    *root = heap->function[1];
    heap->function[1] = heap->function[heap->size--];
    while (1)
    {
        child = parent * 2;
        if ((child + 1 <= heap->size) && (heap->function[child].priority > heap->function[child + 1].priority))
            child++;
        if ((child > heap->size) || (heap->function[child].priority > heap->function[parent].priority))
            break;
        Swap(&heap->function[parent], &heap->function[child]);
        parent = child;
    }
    heap->function[heap->size + 1].priority = 0;
    return(root);
}
