#ifndef _HEAP_H
#define _HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "psuedo_printf.h"

typedef int ElementType;

/*typedef struct	s_functions
{
	void	(*print_l)(int length);
	void	(*print);
	int		usage;
	int		priority;
}				t_fp;
*/

typedef struct	tagHeapNode 
{
	ElementType Data;
	t_fp	fp;
}				HeapNode;

typedef struct	tagHeap {
	HeapNode	*Nodes;
	int			Capacity;
	int			UsedSize;
}	Heap;

HeapNode *HEAP_vertex(Heap *H );
Heap	*HEAP_Create( int InitialSize );
void	HEAP_Destroy( Heap *H );
void	HEAP_Insert( Heap *H, t_fp fp, ElementType Data);
void	HEAP_DeleteMin( Heap *H, HeapNode *Root );
int		HEAP_GetParent( int index );
int		HEAP_GetLeftChild( int index );
void	HEAP_SwapNodes( Heap *H, int Index1, int Index2 );
void	HEAP_PrintNodes( Heap *H );


#endif
