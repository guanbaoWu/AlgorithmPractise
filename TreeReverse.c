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
ST_TREE_NODE* CreateTree()
{
	int i = 0;
	ST_TREE_NODE *pNode = NULL;
	
	scanf("%d", &i);
	if (0 > i)
	{
		return NULL;
	}
	
	printf("TreeNode value:%d\n", i);
	
	pNode = malloc(sizeof(ST_TREE_NODE));
	if (NULL == pNode)
	{
		printf("malloc falied\n");
		return NULL;
	}
	pNode->value = i;
	pNode->pLeft = CreateTree();
	pNode->pRight = CreateTree();
	
	return pNode;
}

int maxDepthTree(ST_TREE_NODE *pRoot)
{
    int LeftDepth = 0;
    int RightDepth = 0;
    
    if (pRoot == NULL)
    {
        return 0;
    }
    
    /**
    * 只有根节点的树的深度为1
    **/
    LeftDepth = maxDepthTree(pRoot->pLeft) + 1;
    RightDepth = maxDepthTree(pRoot->pRight) + 1;
    
    return LeftDepth > RightDepth ? LeftDepth : RightDepth;
    
}

int minDepthTree(ST_TREE_NODE *pRoot)
{
    int LeftDepth = 0;
    int RightDepth = 0;
    
    if (pRoot == NULL)
    {
        return 0;
    }
    
    /**
    * 只有根节点的树的深度为1
    **/
    LeftDepth = maxDepthTree(pRoot->pLeft);
    RightDepth = maxDepthTree(pRoot->pRight);
    
    /**
    * 只存在右子树,返回右子树的深度
    **/
    if (LeftDepth == 0 && RightDepth > 0)
    {
        return RightDepth + 1;
    }
    else if (RightDepth == 0 && LeftDepth > 0)
    {
        return LeftDepth + 1;
    }
    else
    {
        return LeftDepth < RightDepth ? LeftDepth + 1: RightDepth + 1;
    }
    
    return 1;
}

int main()
{
	ST_TREE_NODE *pTree = NULL;
	
	pTree = CreateTree();
	if (NULL == pTree)
	{
		return -1;
	}
	PreOrderReverse(pTree);
	MidOrderReverse(pTree);
	PostOrderReverse(pTree);
	
	printf("maxDepthTree=%d\n", maxDepthTree(pTree));
	printf("minDepthTree=%d\n", minDepthTree(pTree));
	
	return 0;
}








