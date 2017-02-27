#ifndef __BINARY_TREE_H
#define __BINARY_TREE_H

typedef int BTData;

typedef struct _bTreeNode 
{
	BTData data;					//��忡 ����� ������
	struct _bTreeNode* left;		//Ʈ�� ���� ���
	struct _bTreeNode* rigth;		//Ʈ�� ������ ���
}BTreeNode;

BTData GetData(BTreeNode* bt);					//��忡 ����� ������ ��ȯ
void SetData(BTreeNode* bt, BTData data);		//��忡 �����͸� ����. data paramter ����


#endif

