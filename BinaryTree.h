#ifndef __BINARY_TREE_H
#define __BINARY_TREE_H

typedef int BTData;

typedef struct _bTreeNode 
{
	BTData data;					//��忡 ����� ������
	struct _bTreeNode* left;		//Ʈ�� ���� ���
	struct _bTreeNode* right;		//Ʈ�� ������ ���
}BTreeNode;

BTreeNode* MakeBTreeNode(void);					//���� Ʈ�� ��带 �����Ͽ� �ּҰ� ����
BTData GetData(BTreeNode* bt);					//��忡 ����� ������ ����
void SetData(BTreeNode* bt, BTData data);		//��忡 �����͸� ����. data paramter ����
BTreeNode* GetLeftSubTree(BTreeNode* bt);		//���� ����Ʈ���� �ּҰ� ����
BTreeNode* GetRightSubTree(BTreeNode* bt);		//������ ����Ʈ���� �ּҰ� ����
void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);		//main ���� �ڽ� Ʈ���� sub�� ����
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);		//main ������ �ڽ� Ʈ���� sub�� ����

#endif

