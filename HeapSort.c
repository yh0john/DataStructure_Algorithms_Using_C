/*	2017/03/09 �� �ڷᱸ���� �̿��� ���� => �� ����
*	�� �ڷᱸ���� �ٽ� �����ϸ鼭 ����� ���÷� ����.
*	advancedHeap.c �� �����ϸ鼭 �����͸� �ְ� ����.(������ ����!)
*	���� �ð��� 20��!
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