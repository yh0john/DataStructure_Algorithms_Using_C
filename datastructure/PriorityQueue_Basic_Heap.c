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
	//���� ������� check
	if (hp->numOfData == 0) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

int GetParentIDX(int idx)
{
	//�θ� �ε��� �� ��ȯ
	return idx / 2;
}

int GetLeftChildIDX(int idx)
{
	//���� �ڽ� �ε��� �� ��ȯ
	return idx * 2;
}

int GetRightChildIDX(int idx)
{
	//������ �ڽ� �ε��� �� ��ȯ
	return idx * 2 + 1;
}

int GetHighPriorityChildIDX(Heap* hp, int idx)
{
	
	if (GetLeftChildIDX(idx) > hp->numOfData)
	{
		//�ڽ� ��尡 �������� �ʴ´ٸ� 0 ��ȯ
		return 0;
	}
	else if(GetLeftChildIDX(idx)==hp->numOfData){
		//���� �ڽ� ��� �ϳ��� ���� ���
		return GetLeftChildIDX(idx);
	}
	else {

		//���� ����� �켱������ ���� ��� ���� ��� ��ȯ, �ݴ� �� ��� ������ ��� ��ȯ
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
	//ó�� ���� �����ʹ� �켱������ ���� ���ٰ� ����
	//�θ� ���� �켱������ ���ؼ� �θ��庸�� �켱������ Ŭ ���, �ڸ� ��ü
	//�ٷ� ���� ���� �ݺ�
	int idx = hp->numOfData + 1;
	HeapElem nelem = { pr,data };

	while (idx != 1) 
	{
		if (pr < hp->heapArr[GetParentIDX(idx)].pr)
		{
			//���� �θ��庸�� �켱������ ���� ��� �ڸ� ��ü
			hp->heapArr[idx] = hp->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else 
		{
			//���� �θ��庸�� �켱������ ���� ��� while �� break
			break;
		}
	}
}

HData HeapDelete(Heap* hp)
{
	//�켱������ ���� ���� �����͸� ����
	//��, ��Ʈ ��带 ���� �� �� ������ ����� �����͸� ä��
	//���� ���԰����� ������ 

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
