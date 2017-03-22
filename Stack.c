/*
*
*	��ũ�帮��Ʈ ����� ���� ���� 
*	�к� �� �� �ߴ��ǵ� ���̸� ����� �ȳ�����~_~	
*	 
*	Stack : �� �� �������� �������� ��/����� �̷������ ����(linear) �ڷᱸ���̴�.
*			���� �� �����Ͱ� ���߿� ������ ��������(LIFO)������ �̷���� �ִ�.
*
*/

#include<stdio.h>
#include<stdlib.h>

#define FALSE 0
#define TRUE 1

typedef int Data;


//������ �� ĭ�� �ǹ��ϴ� ���
typedef struct _node
{
	Data data;
	struct _node *next;
}Node;

typedef struct _stack
{
	Node* head;	//head�� ����Ű�� ��尡 �ֻ��� ���. ���� ���� ������ �������̴�
}Stack;

void StackInitailize(Stack *pstack)
{
	pstack->head = NULL;
}

int StackIsEmpty(Stack *pstack)
{
	//return  pstack->head == NULL;
	if(pstack->head == NULL)
		return TRUE;
	return FALSE;
}

void Push(Stack *pstack, Data sData)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = sData;

	newNode->next = pstack->head;

	pstack->head = newNode;
}

Data Pop(Stack *pstack)
{
	Data rData;
	Node *rNode;

	if (StackIsEmpty(pstack))
	{
		printf("Stack is Empty");
		exit(-1);
	}

	rData = pstack->head->data;
	rNode = pstack->head;

	pstack->head = pstack->head->next;

	free(rNode);

	return rData;
}

int main(void)
{
	return 0;
}