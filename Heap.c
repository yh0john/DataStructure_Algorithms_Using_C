/*
* 2017.03.03
* 02��27�Ϻ��� ���� Ʈ�� ������ ��ٰ� ������ �Ѿ��.
* �������� �ڷᱸ�� å ����
* AWS ���� �� �ð��� ���ڶ� !
* ��(Heap)����� �켱���� ť(Priority Queue)�� �ۼ� �� ����
* �ڷᱸ���� �˰����� �ۼ� �� �� �ð����⵵ �� �������⵵�� �ѹ� �� ���� �� ����.
* �켱���� ť�� ���� �ϴ� ����� 1.�迭 ,2.���Ḯ��Ʈ 3.��
* �ð����⵵�� ���� �� ��.
*/

#include<stdio.h>

#define TRUE 1
#define FALSE 0
#define HEAP_LEN 100

typedef char HData;
typedef int Priority;

typedef struct _healElement
{
	Priority pr;	//���� �������� ���� ������ �ǹ�
	HData data;
}HeapElem;

typedef struct _heap
{
	int numOfData;
	HeapElem heapArr[HEAP_LEN];
}Heap;

//�Լ� ����

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
	//TEST CODE �ۼ�
	Heap heap;
	HeapInit(&heap);

	HeapInsert(&heap, 'A', 1);	//���� 'A'�� �ְ� �켱������ ����
	HeapInsert(&heap, 'B', 2);	
	HeapInsert(&heap, 'C', 3);	
	printf("%c \n", HeapDelete(&heap));

	HeapInsert(&heap, 'A', 1);	//�ٽ�����
	HeapInsert(&heap, 'B', 2);
	HeapInsert(&heap, 'C', 3);
	printf("%c \n", HeapDelete(&heap));

	while (!HeapIsEmpty(&heap))
		printf("%c \n", HeapDelete(&heap));

	return 0;
}