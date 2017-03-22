/*
* 2017.02.27
* ���� �ڷᱸ�� �ڵ��� �ϰ� �;�����..���� Ʈ�� �ۼ�
* N�� ��ũ�帮��Ʈ �� ����, ť�� �׷��� ���Ŀ� ���� �� ��ȹ
* ����Ʈ�� �ۼ� �� Ʈ�� ��ȸ(Traversal) ���� �� ����
*
*/


#include<stdio.h>
#include<stdlib.h>

typedef int BTData;

/* Tree Node ����ü ���� */

typedef struct _treeNode {
	BTData data;
	struct _treeNode* left;
	struct _treeNode* right;
}BTreeNode;

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
	
	printf("%d \n", bt->data);
	PreorderTraverse(bt->left);
	PreorderTraverse(bt->right);
}

void PostorderTraverse(BTreeNode* bt)
{
	if (bt == NULL)
		return;

	PostorderTraverse(bt->left);
	PostorderTraverse(bt->right);
	printf("%d \n", bt->data);
}

void DeleteNode(BTreeNode* bt)
{
	if (bt == NULL)
		return;

	//Ʈ���� ������ ���ؼ� ��ȸ�� �ʿ��ϴ�.
	DeleteNode(bt->left);
	DeleteNode(bt->right);
	printf("%d \n", bt->data);
}

int main(void) {
	BTreeNode* bt1 = MakeBTreeNode();	//��� bt1 ����
	BTreeNode* bt2 = MakeBTreeNode();	//��� bt2 ����
	BTreeNode* bt3 = MakeBTreeNode();	//��� bt3 ����
	BTreeNode* bt4 = MakeBTreeNode();	//��� bt4 ����

	SetData(bt1, 1);					//bt1�� 1 ����
	SetData(bt2, 2);					//bt2�� 2 ����
	SetData(bt3, 3);					//bt3�� 3 ����
	SetData(bt4, 4);					//bt4�� 4 ����

	MakeLeftSubTree(bt1, bt2);			//bt2�� bt1�� ���� �ڽĳ��� ����
	MakeRigthSubTree(bt1, bt3);			//bt3�� bt1�� ������ �ڽĳ��� ����
	MakeLeftSubTree(bt2, bt4);			//bt4�� bt2�� ���� �ڽĳ��� ����

										//bt1�� ���� �ڽ� ��� ������ ���
	printf("%d \n", GetData(GetLeftSubTre(bt1)));

	//bt1�� ���� �ڽ� ����� ���� �ڽ� ��� ������ ���
	printf("%d \n", GetData(GetLeftSubTree(GetLeftSubTree(bt1))));
}
