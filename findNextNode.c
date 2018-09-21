#include <stidio.h>

typedef struct TREE_NODE{
    struct TREE_NODE *pParent;
	struct TREE_NODE *pLeft;
	struct TREE_NODE *pRight;
	int value;
}ST_TREE_NODE;

/**
* 中序遍历查找指定节点的下一节点
**/
ST_TREE_NODE* FindNextNode(ST_TREE_NODE* pNode)
{
    if (NULL == pNode)
    {
        return NULL;
    }
    
    /**
    * 该节点存在右子树，则节点为右子树的最左节点
    **/
    if (NULL != pNode->pRight)
    {
        ST_TREE_NODE* pTemp = pNode->pRight;
        while(NULL != pTemp && NULL != pTemp->pLeft)
        {
            pTemp = pTemp->pLeft;
        }
        
        return pTemp;
    }
    
    /**
    * 节点不存在右子树
    **/
    else
    {
        /**
        * 该节点是其父节点的左孩子，则下一节点为父节点
        **/
        if ((NULL != pNode->pParent) && pNode == pNode->pParent->pLeft)
        {
            return pNode->pParent;
        }
        /**
        * 该节点是其父节点的右孩子，则下一节点为其上级节点为左孩子时的父节点
        **/
        else if((NULL != pNode->pParent) 
                    && pNode == pNode->pParent->pRight)
        {
            ST_TREE_NODE* pTemp = pNode->pParent;
            while(NULL != pTemp 
                && NULL != pTemp->pParent)
            {
                if (pTemp == pTemp->pParent->pLeft)
                {
                    return pTemp->pParent;
                }
                pTemp = pTemp->pParent;
            }
        }
        
        return NULL;
    }
}

/**
* 创建一个带父节点二叉树,值为-1表示没有孩子节点
**/
ST_TREE_NODE* CreateTree(ST_TREE_NODE* pParent, ST_TREE_NODE** pFindNode)
{
	int  i = 0;
	char c = '\0';
	ST_TREE_NODE *pNode = NULL;
	
	scanf("%d", &i, &c);
	if (0 >= i)
	{
		return NULL;
	}
	
	printf("TreeNode value:%d\n", i);
	
	if (NULL != pParent)
	{
		printf("TreeNode pParent value:%d\n", pParent->value);
	}
	
	pNode = malloc(sizeof(ST_TREE_NODE));
	if (NULL == pNode)
	{
		printf("malloc falied\n");
		return NULL;
	}
	pNode->pParent = pParent;
	pNode->value = i;
	pNode->pLeft = CreateTree(pNode);
	pNode->pRight = CreateTree(pNode);
	
	if (NULL != pFindNode && (c == 'y' || c == 'Y'))
	{
		*pFindNode = pNode;
	}

	return pNode;
}

int main()
{
	ST_TREE_NODE* pTree = NULL;
	ST_TREE_NODE* pFindNode = NULL;
	ST_TREE_NODE* pNextNode = NULL;
	
	pTree = CreateTree(NULL, &pFindNode);
	if (NULL != pFindNode)
	{
		printf("pFindNode value:%d\n", pFindNode->value);
	}

	pNextNode = FindNextNode(pFindNode);
	if (NULL != pNextNode)
	{
		printf("pNextNode value:%d\n", pNextNode->value);
	}
	
	return 0;
}
