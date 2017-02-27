#ifndef __BINARY_TREE_H
#define __BINARY_TREE_H

typedef int BTData;

typedef struct _bTreeNode 
{
	BTData data;					//노드에 저장된 데이터
	struct _bTreeNode* left;		//트리 왼쪽 노드
	struct _bTreeNode* right;		//트리 오른쪽 노드
}BTreeNode;

BTreeNode* MakeBTreeNode(void);					//이진 트리 노드를 생성하여 주소값 리턴
BTData GetData(BTreeNode* bt);					//노드에 저장된 데이터 리턴
void SetData(BTreeNode* bt, BTData data);		//노드에 데이터를 저장. data paramter 저장
BTreeNode* GetLeftSubTree(BTreeNode* bt);		//왼쪽 서브트리의 주소값 리턴
BTreeNode* GetRightSubTree(BTreeNode* bt);		//오른쪽 서브트리의 주소값 리턴
void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);		//main 왼쪽 자식 트리에 sub를 연결
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);		//main 오른쪽 자식 트리에 sub를 연결



/* 루트 노드를 언제 방문 할 것인지*/
void InorderTraverse(BTreeNode* bt);		//중위순회
void PreorderTraverse(BTreeNode* bt);		//전위순회
void PostorderTraverse(BTreeNode* bt);		//후위순회
#endif

