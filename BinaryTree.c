/*
* 2017.02.27
* 문득 자료구조 코딩이 하고 싶어져서..이진 트리 작성
* N중 링크드리스트 및 스택, 큐는 그래프 이후에 구현 할 계획
* 이진트리 작성 후 트리 순회(Traversal) 구현 할 예정
*
*/


#include<stdio.h>
#include<stdlib.h>
#include "BinaryTree.h"
#include "BinaryTree2.h"


BTreeNode* MakeBTreeNode(void)
{
	BTreeNode* bt = (BTreeNode *)malloc(sizeof(BTreeNode));
	bt->left = NULL;
	bt->right = NULL;
	return bt;
}

BTData GetData(BTreeNode* bt) 
{
	return bt->data;
}

void SetData(BTreeNode*bt, BTData data) 
{
	bt->data = data;
}


BTreeNode* GetLeftSubTree(BTreeNode* bt)
{
	return bt->left;
}

BTreeNode* GetRightSubTree(BTreeNode* bt)
{
	return bt->right;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->left != NULL)
		free(main->left);

	main->left = sub;
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->right != NULL)
		free(main->right);

	main->right = sub;

}

void InorderTraverse(BTreeNode* bt) 
{
	if (bt == NULL)
		return;

	InorderTraverse(bt->left);
	printf("%d \n",bt->data);
	InorderTraverse(bt->right);
}

void PreorderTraverse(BTreeNode* bt)
{
	if (bt == NULL)
		return;
}

void PostorderTraverse(BTreeNode* bt)
{
	if (bt == NULL)
		return;
}



int main(void) {
	BTreeNode* bt1 = MakeBTreeNode();	//노드 bt1 생성
	BTreeNode* bt2 = MakeBTreeNode();	//노드 bt2 생성
	BTreeNode* bt3 = MakeBTreeNode();	//노드 bt3 생성
	BTreeNode* bt4 = MakeBTreeNode();	//노드 bt4 생성

	SetData(bt1, 1);					//bt1에 1 저장
	SetData(bt2, 2);					//bt2에 2 저장
	SetData(bt3, 3);					//bt3에 3 저장
	SetData(bt4, 4);					//bt4에 4 저장

	MakeLeftSubTree(bt1, bt2);			//bt2를 bt1의 왼쪽 자식노드로 설정
	MakeRigthSubTree(bt1, bt3);			//bt3를 bt1의 오른쪽 자식노드로 설정
	MakeLeftSubTree(bt2, bt4);			//bt4를 bt2의 왼쪽 자식노드로 설정

										//bt1의 왼쪽 자식 노드 데이터 출력
	printf("%d \n", GetData(GetLeftSubTre(bt1)));

	//bt1의 왼쪽 자식 노드의 왼쪽 자식 노드 데이터 출력
	printf("%d \n", GetData(GetLeftSubTree(GetLeftSubTree(bt1))));
}