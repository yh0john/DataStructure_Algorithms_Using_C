#include<stdio.h>

#define FALSE 0
#define TRUE 1

//advancedHeap 기반의 Priority Queue 작성
//큰 의미 없는듯..
typedef Heap PQueue;
typedef HData PQData;

void PQueueInit(PQueue* ppq)
{
	HeapInit(&ppq);
}

void PQueueInsert(PQueue* ppq, PQData data)
{
	HeapInsert(&ppq, data);
}

PQData PQueueDelete(PQueue* ppq)
{
	return HeapDelete(&ppq);
}

int PQueueIsEmpty(PQueue* ppq)
{
	return HeapIsEmpty(&ppq);
}
