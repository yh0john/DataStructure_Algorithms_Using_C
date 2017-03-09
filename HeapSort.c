/*	2017/03/09 힙 자료구조를 이용한 정렬 => 힙 정렬
*	힙 자료구조를 다시 구현하면서 기억을 떠올려 본다.
*	advancedHeap.c 를 구현하면서 데이터를 넣고 뺀다.(정렬의 과정!)
*	제한 시간은 20분!
*
*
*
*/

#include<stdio.h>

#define TRUE 1
#define FALSE 0
#define MAX_LEN 100

typedef int HData;
typedef int PriorityCompare(HData d1, HData d2);

typedef struct _heap
{

	HData HeapArr[MAX_LEN];
	PriorityCompare* compare;
	int numOfData;
}Heap;

void HeapInit(Heap* hp,PriorityCompare comp)
{
	hp->numOfData = 0;
	hp->compare = comp;
}

int GetLeftChildIDX(int idx)
{

}
int GetRightChildIDX(int idx)
{

}

int GetHighPriorityChildIDX(int idx)
{

}

int GetParentIDX(int idx)
{

}

HData HeapDelete(Heap* hp)
{

}

void HeapInsert(Heap* hp, HData data)
{

}

void HeapSort(int arr[], int length, PriorityCompare comp)
{

}