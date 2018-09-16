#include <stdio.h>
#include <stdlib.h>

typedef struct TREE_NODE{
	struct TREE_NODE *pLeft;
	struct TREE_NODE *pRight;
	int value;
}ST_TREE_NODE;

/**
* ǰ�����
**/
void PreOrderReverse(ST_TREE_NODE *pTree)
{
	if (NULL == pTree || (NULL == pTree->pLeft && NULL == pTree->pRight))
	{
		return;
	}
	
	/**
	* ǰ�����,�ȱ�����,�ٱ���������,������������
	**/
	printf("PreOrderReverse value:%d\n", pTree->value);
	PreOrderReverse(pTree->pLeft);
	PreOrderReverse(pTree->pRight);
	
}

/**
* �������
**/
void MidOrderReverse(ST_TREE_NODE *pTree)
{
	if (NULL == pTree || (NULL == pTree->pLeft && NULL == pTree->pRight))
	{
		return;
	}
	
	/**
	* �������,�ȱ���������,�ٱ���������
	**/
	MidOrderReverse(pTree->pLeft);
	printf("MidOrderReverse value:%d\n", pTree->value);
	MidOrderReverse(pTree->pRight);
	
}

/**
* �������
**/
void PostOrderReverse(ST_TREE_NODE *pTree)
{
	if (NULL == pTree || (NULL == pTree->pLeft && NULL == pTree->pRight))
	{
		return;
	}
	
	/**
	* �ȱ���������,�ٱ���������,���������ڵ�
	**/
	PostOrderReverse(pTree->pLeft);
	PostOrderReverse(pTree->pRight);
	printf("PostOrderReverse value:%d\n", pTree->value);
	
}

/**
* ����һ��������,ֵΪ-1��ʾû�к��ӽڵ�
**/
void CreateTree(ST_TREE_NODE *pTree)
{
	int i = 0;
	ST_TREE_NODE *pNode = NULL;
	
	scanf("%d", &i);
	if (0 > i)
	{
		return;
	}
	
	printf("TreeNode value:%d\n", i);
	pTree->value = i;
	
	/**
	* ����������
	**/
	pNode = malloc(sizeof(ST_TREE_NODE));
	if (NULL == pNode)
	{
		printf("malloc falied\n");
		return;
	}
	
	CreateTree(pNode);

	printf("Node parent value:%d\n", i);
	pTree->pLeft = pNode;
	
	/**
	* ����������
	**/
	pNode = malloc(sizeof(ST_TREE_NODE));
	if (NULL == pNode)
	{
		printf("malloc falied\n");
		return;
	}
	
	CreateTree(pNode);
	printf("Node parent value:%d\n", i);
	pTree->pRight = pNode;
}

int main()
{
	ST_TREE_NODE stTree;
	
	CreateTree(&stTree);
	PreOrderReverse(&stTree);
	MidOrderReverse(&stTree);
	PostOrderReverse(&stTree);
	
	return 0;
}








