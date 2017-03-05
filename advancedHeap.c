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


int main(void) {
		
	return 0;
}