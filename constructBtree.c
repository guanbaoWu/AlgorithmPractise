#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct TREE_NODE{
	struct TREE_NODE *pLeft;
	struct TREE_NODE *pRight;
	int value;
}ST_TREE_NODE;

/**
* @startPreOrder:前序遍历序列起始点
* @endPreOrder:前序遍历序列终止点
* @endInOrder:中序序遍历序列起始点
* @endInOrder:中序遍历序列终止点
* 返回二叉树结点
**/
ST_TREE_NODE* Construct
(
	int *startPreOrder, 
	int *endPreOrder, 
	int *startInOrder,
	int *endInOrder
)
{
	int *startOrder = NULL;
	
	int length = 0;
	
	ST_TREE_NODE * pTreeNode = (ST_TREE_NODE *)malloc(sizeof(ST_TREE_NODE));
	
	assert(pTreeNode != NULL);
	
	/**
	* 前序遍历序列的首个元素即为根节点
	**/
	pTreeNode->value = startPreOrder[0];
	pTreeNode->pLeft = NULL;
	pTreeNode->pRight = NULL;
	
	/**
	* 递归完成
	**/
	if (startPreOrder == endPreOrder)
	{
		if (startInOrder == endInOrder && *endInOrder == *startPreOrder)
		{
			return pTreeNode;
		}
		else
		{
			printf("error Tree!\n");
			return NULL;
		}
	}
	
	/**
	* 查找中序遍历的根节点,以此分成左右两颗子树
	**/
	startOrder = startInOrder;
	while(startOrder < endInOrder && *startOrder != *startPreOrder)
		++startOrder;
	
	if (startOrder == endInOrder && *startOrder != *startPreOrder)
	{
	    return NULL;
	}
	
	length = startOrder - startInOrder;
	
	/**
	* 存在左子树
	**/
	if (length > 0)
	{
		pTreeNode->pLeft = Construct(startPreOrder+1, startPreOrder+length,
									startInOrder, startOrder - 1);
	}
	
	/**
	* 右子树存在
	**/
	if (endInOrder - startOrder > 0)
	{
		pTreeNode->pRight = Construct(startPreOrder+length+1, endPreOrder,
									startOrder+1, endInOrder);
	}


	return pTreeNode;

}


/**
* 前序遍历第一个节点为根节点或者子树的根节点
* 中序遍历,根节点将会将序列分成左右子树
* 递归中序遍历分成左右子树
**/
ST_TREE_NODE* BtreeConstruct(int *preOrder, int *inOrder, int length)
{
	if (NULL == preOrder || NULL == inOrder || 0 >= length)
	{
		return NULL;
	}
	
	return Construct(preOrder, preOrder+length-1, inOrder, inOrder+length-1);
}
