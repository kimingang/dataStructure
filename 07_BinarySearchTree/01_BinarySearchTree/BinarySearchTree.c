#include <stdio.h>
#include "BinaryTree.h"
#include "BinarySearchTree.h"

void BSTMakeAndInit(BTreeNode ** pRoot)
{
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode * bst)
{
	return GetData(bst);
}

void BSTInsert(BTreeNode ** pRoot, BSTData data)
{
	BTreeNode * pNode = NULL;    // parent node
	BTreeNode * cNode = *pRoot;    // current node
	BTreeNode * nNode = NULL;    // new node

	// ���ο� ��尡 �߰��� ��ġ�� ã�´�.
	while(cNode != NULL)
	{
		if(data == GetData(cNode))
			return;    // Ű�� �ߺ��� ������� ����

		pNode = cNode;

		if(GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}
	
	// pNode�� ���� ��忡 �߰��� �� ����� ����
	nNode = MakeBTreeNode();    // �� ����� ����
	SetData(nNode, data);    // �� ��忡 ������ ����

	// pNode�� ���� ��忡 �� ��带 �߰�
	if(pNode != NULL)    // �� ��尡 ��Ʈ ��尡 �ƴ϶��,
	{
		if(data < GetData(pNode))
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	}
	else    // �� ��尡 ��Ʈ �����,
	{
		*pRoot = nNode;
	}
}

BTreeNode * BSTSearch(BTreeNode * bst, BSTData target)
{
	BTreeNode * cNode = bst;    // current node
	BSTData cd;    // current data

	while(cNode != NULL)
	{
		cd = GetData(cNode);

		if(target == cd)
			return cNode;
		else if(target < cd)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	return NULL;
}

/*
#include <stdio.h>
#include "BinarySearchTree.h"

int main(void)
{
	BTreeNode * bstRoot;
	BTreeNode * sNode;    // search node

	BSTMakeAndInit(&bstRoot);

	BSTInsert(&bstRoot, 9);
	BSTInsert(&bstRoot, 1);
	BSTInsert(&bstRoot, 6);
	BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 8);
//	BSTInsert(&bstRoot, 4);
	BSTInsert(&bstRoot, 3);
	BSTInsert(&bstRoot, 5);
//	BSTInsert(&bstRoot, 7);

	sNode = BSTSearch(bstRoot, 1);
	if(sNode == NULL)
		printf("Ž�� ���� \n");
	else
		printf("Ž���� ������ Ű�� ��: %d \n", BSTGetNodeData(sNode));

	sNode = BSTSearch(bstRoot, 4);
	if(sNode == NULL)
		printf("Ž�� ���� \n");
	else
		printf("Ž���� ������ Ű�� ��: %d \n", BSTGetNodeData(sNode));

	sNode = BSTSearch(bstRoot, 6);
	if(sNode == NULL)
		printf("Ž�� ���� \n");
	else
		printf("Ž���� ������ Ű�� ��: %d \n", BSTGetNodeData(sNode));

	sNode = BSTSearch(bstRoot, 7);
	if(sNode == NULL)
		printf("Ž�� ���� \n");
	else
		printf("Ž���� ������ Ű�� ��: %d \n", BSTGetNodeData(sNode));

	return 0;
}
*/