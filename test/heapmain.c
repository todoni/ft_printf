#include "psuedo_printf.h"
#include "arrayheap.h"
#include <time.h>

int main()
{
    Heap	heap;
	t_fp	fp[8];

	srand(time(NULL));
	for (int i = 0; i < 8; i++)
		fp[i].priority = rand() % 8;
    for (int i = 0; i < 8; i++)
        printf("%d ", fp[i].priority);
    printf("\n");
	initializeHeap(&heap);
    for (int i = 0; i < 8; i++)
		Insert(&heap, fp[i]);
    for (int i = 0; i < 9; i++)
        printf("%d ", heap.function[i].priority);
    printf("\n");

	while(heap.size)
    	printf("%d\n", Delete(&heap).priority);

    for (int i = 0; i < 9; i++)
        printf("%d ", heap.function[i].priority);
    printf("\n");
    return 0;
}
