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
    * ֻ�и��ڵ���������Ϊ1
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
    * ֻ�и��ڵ���������Ϊ1
    **/
    LeftDepth = maxDepthTree(pRoot->pLeft);
    RightDepth = maxDepthTree(pRoot->pRight);
    
    /**
    * ֻ����������,���������������
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








