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
	//ó�� ���� �� ��ġ�� �켱������ ���� ���� ������ �����Ѵ�.
	//�θ� ���� �켱���� �� �� ���Ե� ��尡 �켱������ ���� ��� switching
	//�θ� ��庸�� �켱������ ���� ���, �� �ڸ��� ����� ������ġ�� �ȴ�.

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
	//���� �켱������ ���� ������(������������)���� ���� �켱������ �����͸� ã���� �� break;

	//�� ã���� ���, �ڽ� idx ���� �θ� idx������ ����
	//�ٽ� �˻�
	
	//���� �� ������(�켱������ ���� ū ������)
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
	//�� �Լ��� ���ؼ� ������ ����� �켱������ Ŭ ���, ������ �ڽĳ�带 ��ȯ
	//�� �ݴ�� ���� �ڽ� ��带 ��ȯ�Ѵ�.
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
/* Test�� �켱���� �� �Լ� ���*/
int DataPriorityCompare(char h1, char h2)
{
	return h2 - h1;
}

int main(void) {
	//Test Code �ۼ�
	//���Ŀ��� ��ȭ�� �� ����� �켱���� ť�� �ۼ��Ѵ�.
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