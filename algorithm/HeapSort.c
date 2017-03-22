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
	//MAX HEAP 기준으로 루트 노드의 데이터가 우선순위가 가장 높으므로 삭제 대상이 된다.
	//루트노드를 삭제하고 우선순위가 가장 낮은 마지막 노드를 루트노드에 삽입한다.
	//이후는 삽입 알고리즘과 동일하다

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