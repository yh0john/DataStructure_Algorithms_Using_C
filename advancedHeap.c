/*
* 2017.03.04
* ���� ������ �켱������ ���� �� �ִ� �Լ��� ���
* �Լ� �����ͷ� ����ڰ� ���� ��� �ϰԲ� �ۼ���
*/

#include<stdio.h>

#define TRUE 1
#define FALSE 0
#define HEAP_LEN 100

typedef char HData;
typedef int PriorityCompare(HData d1, HData d2);

typedef struct _heap
{
	PriorityCompare* compare;		//����ڰ� main������ �����ؼ�  Init �۾��� ���� ����ؾ���
	int numOfData;
	HData heapArr[HEAP_LEN];
}Heap;


int main(void) {
		
	return 0;
}