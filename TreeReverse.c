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

/**
* 前序遍历
**/
void PreOrderReverse(ST_TREE_NODE *pTree)
{
	if (NULL == pTree)
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
	if (NULL == pTree)
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
	if (NULL == pTree)
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
	if (0 >= i)
	{
		return NULL;
	}

	//getchar();
	
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
	
	//printf("ParentNode value:%d\n", i);

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
	ST_TREE_NODE *pTreeCreate = NULL;

	int preOrder[] = {1,2,4,7,3,5,6,8};
	int inOrder[] = {4,7,2,1,5,3,8,6};
	
	pTreeCreate = CreateTree();
	if (NULL == pTreeCreate)
	{
		return -1;
	}
	
	pTree = BtreeConstruct(preOrder, inOrder, sizeof(preOrder)/sizeof(preOrder[0]));
	
	PreOrderReverse(pTree);
	MidOrderReverse(pTree);
	PostOrderReverse(pTree);
	
	PreOrderReverse(pTreeCreate);
	MidOrderReverse(pTreeCreate);
	PostOrderReverse(pTreeCreate);

	printf("maxDepthTree=%d\n", maxDepthTree(pTree));
	printf("minDepthTree=%d\n", minDepthTree(pTree));
	
	return 0;
}








