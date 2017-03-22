/*
* 2017.03.03
* 02월27일부터 이진 트리 가지고 놀다가 힙으로 넘어옴.
* 윤성우의 자료구조 책 참조
* AWS 연동 할 시간도 모자람 !
* 힙(Heap)기반의 우선순위 큐(Priority Queue)를 작성 할 예정
* 자료구조나 알고리즘을 작성 할 때 시간복잡도 및 공간복잡도를 한번 쯤 생각 해 볼것.
* 우선순위 큐를 구현 하는 방법은 1.배열 ,2.연결리스트 3.힙
* 시간복잡도를 따져 볼 것.
*/


#include<stdio.h>

#define TRUE 1
#define FALSE 0
#define HEAP_LEN 100

typedef char HData;
typedef int Priority;

typedef struct _healElement
{
	Priority pr;	//값이 작을수록 높은 순위를 의미
	HData data;
}HeapElem;

typedef struct _heap
{
	int numOfData;
	HeapElem heapArr[HEAP_LEN];
}Heap;

//함수 정의

void HeapInit(Heap* hp) 
{
	hp->numOfData = 0;
}
 

int HeapIsEmpty(Heap* hp)
{
	//힙이 비었는지 check
	if (hp->numOfData == 0) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

int GetParentIDX(int idx)
{
	//부모 인덱스 값 반환
	return idx / 2;
}

int GetLeftChildIDX(int idx)
{
	//왼쪽 자식 인덱스 값 반환
	return idx * 2;
}

int GetRightChildIDX(int idx)
{
	//오른쪽 자식 인덱스 값 반환
	return idx * 2 + 1;
}

int GetHighPriorityChildIDX(Heap* hp, int idx)
{
	
	if (GetLeftChildIDX(idx) > hp->numOfData)
	{
		//자식 노드가 존재하지 않는다면 0 반환
		return 0;
	}
	else if(GetLeftChildIDX(idx)==hp->numOfData){
		//왼쪽 자식 노드 하나만 있을 경우
		return GetLeftChildIDX(idx);
	}
	else {

		//왼쪽 노드의 우선순위가 높을 경우 왼쪽 노드 반환, 반대 일 경우 오른쪽 노드 반환
		if (GetLeftChildIDX(idx) > GetRightChildIDX(idx)) {
			return GetLeftChildIDX(idx);
		}
		else {
			GetRightChildIDX(idx);
		}
	}
}

void HeapInsert(Heap* hp,HData data,Priority pr)
{
	//처음 들어온 데이터는 우선순위가 가장 낮다고 가정
	//부모 노드와 우선순위를 비교해서 부모노드보다 우선순위가 클 경우, 자리 교체
	//바로 위의 과정 반복
	int idx = hp->numOfData + 1;
	HeapElem nelem = { pr,data };

	while (idx != 1) 
	{
		if (pr < hp->heapArr[GetParentIDX(idx)].pr)
		{
			//만약 부모노드보다 우선순위가 높을 경우 자리 교체
			hp->heapArr[idx] = hp->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else 
		{
			//만약 부모노드보다 우선순위가 낮을 경우 while 문 break
			break;
		}
	}
}

HData HeapDelete(Heap* hp)
{
	//우선순위가 가장 높은 데이터를 삭제
	//즉, 루트 노드를 삭제 한 후 마지막 노드의 데이터를 채움
	//이후 삽입과정과 동일함 

	HData retData = (hp->heapArr[1]).data;
	HeapElem lastElem = hp->heapArr[hp->numOfData];

	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHighPriorityIDX(hp,parentIdx)) {
		if (lastElem.pr<=hp->heapArr[childIdx].pr)
			break;
		hp->heapArr[parentIdx] = hp->heapArr[childIdx];
		parentIdx = childIdx;
	}

	hp->heapArr[parentIdx] = lastElem;
	hp->numOfData -= 1;
	return retData;

}

int main(void) {
	//TEST CODE 작성
	Heap heap;
	HeapInit(&heap);

	HeapInsert(&heap, 'A', 1);	//문자 'A'를 최고 우선순위로 저장
	HeapInsert(&heap, 'B', 2);	
	HeapInsert(&heap, 'C', 3);	
	printf("%c \n", HeapDelete(&heap));

	HeapInsert(&heap, 'A', 1);	//다시저장
	HeapInsert(&heap, 'B', 2);
	HeapInsert(&heap, 'C', 3);
	printf("%c \n", HeapDelete(&heap));

	while (!HeapIsEmpty(&heap))
		printf("%c \n", HeapDelete(&heap));

	return 0;
}
