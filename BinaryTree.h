#ifndef __BINARY_TREE_H
#define __BINARY_TREE_H

typedef int BTData;

typedef struct _bTreeNode 
{
	BTData data;					//노드에 저장된 데이터
	struct _bTreeNode* left;		//트리 왼쪽 노드
	struct _bTreeNode* rigth;		//트리 오른쪽 노드
}BTreeNode;

BTData GetData(BTreeNode* bt);					//노드에 저장된 데이터 반환
void SetData(BTreeNode* bt, BTData data);		//노드에 데이터를 저장. data paramter 저장


#endif

