/*
* 2017.03.04
* 기존 힙에서 우선순위를 정할 수 있는 함수를 등록
* 함수 포인터로 사용자가 직접 등록 하게끔 작성함
*/

#include<stdio.h>

#define TRUE 1
#define FALSE 0
#define HEAP_LEN 100

typedef char HData;
typedef int PriorityCompare(HData d1, HData d2);

typedef struct _heap
{
	PriorityCompare* compare;		//사용자가 main문에서 정의해서  Init 작업떄 직접 등록해야함
	int numOfData;
	HData heapArr[HEAP_LEN];
}Heap;


void HeapInit(Heap* hp, PriorityCompare pc) 
{
	hp->numOfData = 0;
	hp->compare = pc;
}

int HeapIsEmpty(Heap* hp)
{
	if (hp->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

void HeapInsert(Heap* hp, HData data)
{
	//처음 삽입 될 위치는 우선순위가 제일 낮은 곳으로 가정한다.
	//부모 노드와 우선순위 비교 후 삽입된 노드가 우선순위가 높을 경우 switching
	//부모 노드보다 우선순위가 낮을 경우, 그 자리가 노드의 삽입위치가 된다.

	int idx = hp->numOfData+1;

	while (idx != 1)
	{
		if (hp->compare(data, hp->heapArr[GetParentIDX(idx)]) > 0)
		{
			hp->heapArr[idx] = hp->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
		{
			break;
		}
	}

	hp->heapArr[idx] = data;
	hp->numOfData += 1;
	
}

HData HeapDelete(Heap* hp)
{
	//제일 우선순위가 낮은 데이터(마지막데이터)보다 낮은 우선순위의 데이터를 찾았을 때 break;

	//못 찾았을 경우, 자식 idx 값을 부모 idx값으로 대입
	//다시 검색
	
	//삭제 할 데이터(우선순위가 가장 큰 데이터)
	HData delData = hp->heapArr[1];
	HData lastElem = hp->heapArr[hp->numOfData];

	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHighPriorityChilIDX(parentIdx))
	{
		if (hp->compare(lastElem, hp->heapArr[childIdx]) >= 0)
		{
			break;
		}
		else
		{
			hp->heapArr[parentIdx] = hp->heapArr[childIdx];
			parentIdx = childIdx;
		}
	}

	hp->heapArr[parentIdx] = lastElem;
	hp->numOfData -= 1;
	return delData;
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

int GetHighPriorityChilIDX(int idx,Heap* hp) 
{
	//비교 함수를 통해서 오른쪽 노드의 우선순위가 클 경우, 오른쪽 자식노드를 반환
	//그 반대는 왼쪽 자식 노드를 반환한다.
	if (GetLeftChildIDX(idx) > hp->numOfData)
		return 0;
	else if (GetLeftChildIDX == hp->numOfData)
		return GetLeftChildIDX(idx);
	else
	{
		if (hp->compare(hp->heapArr[GetLeftChildIDX(idx)], hp->heapArr[GetRightChildIDX(idx)]) < 0)
		{
			return GetRightChildIDX(idx);
		}
		else {
			return GetLeftChildIDX(idx);
		}
	}

}
/* Test용 우선순위 비교 함수 등록*/
int DataPriorityCompare(char h1, char h2)
{
	return h2 - h1;
}

int main(void) {
	//Test Code 작성
	//이후에는 진화된 힙 기반의 우선순위 큐를 작성한다.
	Heap heap;
	HeapInit(&heap, DataPriorityCompare);

	HeapInsert(&heap, 'A');
	HeapInsert(&heap, 'B');
	HeapInsert(&heap, 'C');

	printf("%c \n", HeapDelete(&heap));

	HeapInsert(&heap, 'A');
	HeapInsert(&heap, 'B');
	HeapInsert(&heap, 'C');

	printf("%c \n", HeapDelete(&heap));

	while (!HeapIsEmpty(&heap))
	{
		printf("%c \n", HeapDelete(&heap));
	}

	return 0;
}