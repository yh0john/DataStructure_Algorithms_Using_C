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
	return idx * 2;
}
int GetRightChildIDX(int idx)
{
	return idx * 2 + 1;
}

int GetParentIDX(int idx)
{
	return idx / 2;
}

int GetHighPriorityChildIDX(int idx, Heap* hp)
{

}


HData HeapDelete(Heap* hp)
{
	//MAX HEAP �������� ��Ʈ ����� �����Ͱ� �켱������ ���� �����Ƿ� ���� ����� �ȴ�.
	//��Ʈ��带 �����ϰ� �켱������ ���� ���� ������ ��带 ��Ʈ��忡 �����Ѵ�.
	//���Ĵ� ���� �˰���� �����ϴ�

	HData retData = hp->HeapArr[1];
	HData lastElem = hp->HeapArr[hp->numOfData];

	int parent = 1;
	int child;

}

void HeapInsert(Heap* hp, HData data)
{

}

void HeapSort(int arr[], int length, PriorityCompare comp)
{

}