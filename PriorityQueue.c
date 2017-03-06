#include<stdio.h>

#define FALSE 0
#define TRUE 1

//advancedHeap ����� Priority Queue �ۼ�
//ū �ǹ� ���µ�..
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
