/*
*
*	링크드리스트 기반의 스택 구현 
*	학부 때 다 했던건데 왜이리 기억이 안나는지~_~	
*	 
*	Stack : 한 쪽 끝에서만 데이터의 입/출력이 이루어지는 선형(linear) 자료구조이다.
*			먼저 들어간 데이터가 나중에 나오는 선입후출(LIFO)구조로 이루어져 있다.
*
*/

#include<stdio.h>
#include<stdlib.h>

#define FALSE 0
#define TRUE 1

typedef int Data;


//스택의 각 칸을 의미하는 노드
typedef struct _node
{
	Data data;
	struct _node *next;
}Node;

typedef struct _stack
{
	Node* head;	//head가 가리키는 노드가 최상위 노드. 제일 먼저 나오는 데이터이다
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