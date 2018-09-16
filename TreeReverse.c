#include <stdio.h>
#include <stdlib.h>

typedef struct TREE_NODE{
	struct TREE_NODE *pLeft;
	struct TREE_NODE *pRight;
	int value;
}ST_TREE_NODE;

/**
* 前序遍历
**/
void PreOrderReverse(ST_TREE_NODE *pTree)
{
	if (NULL == pTree || (NULL == pTree->pLeft && NULL == pTree->pRight))
	{
		return;
	}
	
	/**
	* 前序遍历,先遍历根,再遍历左子树,最后遍历右子树
	**/
	printf("PreOrderReverse value:%d\n", pTree->value);
	PreOrderReverse(pTree->pLeft);
	PreOrderReverse(pTree->pRight);
	
}

/**
* 中序遍历
**/
void MidOrderReverse(ST_TREE_NODE *pTree)
{
	if (NULL == pTree || (NULL == pTree->pLeft && NULL == pTree->pRight))
	{
		return;
	}
	
	/**
	* 中序遍历,先遍历左子树,再遍历右子树
	**/
	MidOrderReverse(pTree->pLeft);
	printf("MidOrderReverse value:%d\n", pTree->value);
	MidOrderReverse(pTree->pRight);
	
}

/**
* 后序遍历
**/
void PostOrderReverse(ST_TREE_NODE *pTree)
{
	if (NULL == pTree || (NULL == pTree->pLeft && NULL == pTree->pRight))
	{
		return;
	}
	
	/**
	* 先遍历左子树,再遍历右子树,最后遍历根节点
	**/
	PostOrderReverse(pTree->pLeft);
	PostOrderReverse(pTree->pRight);
	printf("PostOrderReverse value:%d\n", pTree->value);
	
}

/**
* 创建一个二叉树,值为-1表示没有孩子节点
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
	* 创建左子树
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
	* 创建右子树
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








