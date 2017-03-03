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
	if (hp->numOfData == 0) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

void HeapInsert(Heap* hp,HData data,Priority pr)
{

}

HData HeapDelete(Heap* hp)
{

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