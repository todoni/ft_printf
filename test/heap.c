#include "heap.h"
#include "psuedo_printf.h"

Heap	*HEAP_Create( int InitialSize ) {
	Heap	*NewHeap = (Heap*) malloc( sizeof( Heap ) );
	NewHeap->Capacity = InitialSize;
	NewHeap->UsedSize = 0;
	NewHeap->Nodes = (HeapNode*) malloc( sizeof( HeapNode ) * NewHeap->Capacity );
	return NewHeap;
}

void	HEAP_Destroy( Heap *H ) {
	free( H->Nodes );
	free( H );
}

void	HEAP_Insert( Heap *H, t_fp fp, ElementType NewData)
{
	
	int	CurrentPosition = H->UsedSize;
	int	ParentPosition = HEAP_GetParent( CurrentPosition );

	if (H->UsedSize == H->Capacity) {
		H->Capacity *= 2;
		H->Nodes = (HeapNode*) realloc( H->Nodes, sizeof( HeapNode ) * H->Capacity );
	}
	H->Nodes[CurrentPosition].Data = NewData;
	H->Nodes[CurrentPosition].fp = fp;
	
	while ( CurrentPosition > 0 && H->Nodes[CurrentPosition].Data < H->Nodes[ParentPosition].Data ) {
		HEAP_SwapNodes( H, CurrentPosition, ParentPosition );

		CurrentPosition = ParentPosition;
		ParentPosition = HEAP_GetParent( CurrentPosition );
	}

	H->UsedSize++;
}

HeapNode *HEAP_vertex(Heap *H)
{
    return &H->Nodes[0]; 
}

void	HEAP_DeleteMin( Heap *H, HeapNode *Root ) {
	int	ParentPosition = 0;
	int	LeftPosition   = 0;
	int	RightPosition  = 0;

	/* save min in Root */
	memcpy(Root, &H->Nodes[0], sizeof(HeapNode));
	memset(&H->Nodes[0], 0, sizeof(HeapNode));

	H->UsedSize--;
	/* copy last node's data to first node */
	HEAP_SwapNodes( H, 0, H->UsedSize );

	LeftPosition  = HEAP_GetLeftChild( 0 );
	RightPosition = LeftPosition + 1;

	while (1) {
		int	SelectedChild = 0;

		if ( LeftPosition >= H->UsedSize )
			break ;

		if ( RightPosition >= H->UsedSize )
			SelectedChild = LeftPosition;
		else {
			if ( H->Nodes[LeftPosition].Data > H->Nodes[RightPosition].Data )
				SelectedChild = RightPosition;
			else
				SelectedChild = LeftPosition;
		}

		if ( H->Nodes[SelectedChild].Data < H->Nodes[ParentPosition].Data ) {
			HEAP_SwapNodes(H, ParentPosition, SelectedChild);
			ParentPosition = SelectedChild;
		}
		else
			break ;

		LeftPosition  = HEAP_GetLeftChild(ParentPosition);
		RightPosition = LeftPosition + 1;
	}

	if ( H->UsedSize < ( H->Capacity / 2 ) ) {
		H->Capacity /= 2;
		H->Nodes = (HeapNode*) realloc( H->Nodes, sizeof( HeapNode ) * H->Capacity );
	}
}

int		HEAP_GetParent( int Index ) {
	return (int)((Index - 1) / 2);
}

int		HEAP_GetLeftChild( int Index ) {
	return ((2 * Index) + 1);
}

void	HEAP_SwapNodes( Heap *H, int Index1, int Index2 ) {
	int CopySize = sizeof( HeapNode );
	HeapNode	*Temp = (HeapNode*) malloc( CopySize );

	memcpy(Temp, 			  &H->Nodes[Index1], CopySize);
	memcpy(&H->Nodes[Index1], &H->Nodes[Index2], CopySize);
	memcpy(&H->Nodes[Index2], Temp,				 CopySize);

	free(Temp);
}

void	HEAP_PrintNodes( Heap *H ) {
	if (!H->UsedSize)
		return ;
	int	i;
	for (i = 0; i < H->UsedSize; i++) {
        printf("%d\n", H->Nodes[i].Data);
	}
	printf("\n");
}
