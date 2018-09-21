#include <stidio.h>

typedef struct TREE_NODE{
    struct TREE_NODE *pParent;
	struct TREE_NODE *pLeft;
	struct TREE_NODE *pRight;
	int value;
}ST_TREE_NODE;

/**
* �����������ָ���ڵ����һ�ڵ�
**/
ST_TREE_NODE* FindNextNode(ST_TREE_NODE* pNode)
{
    if (NULL == pNode)
    {
        return NULL;
    }
    
    /**
    * �ýڵ��������������ڵ�Ϊ������������ڵ�
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
    * �ڵ㲻����������
    **/
    else
    {
        /**
        * �ýڵ����丸�ڵ�����ӣ�����һ�ڵ�Ϊ���ڵ�
        **/
        if ((NULL != pNode->pParent) && pNode == pNode->pParent->pLeft)
        {
            return pNode->pParent;
        }
        /**
        * �ýڵ����丸�ڵ���Һ��ӣ�����һ�ڵ�Ϊ���ϼ��ڵ�Ϊ����ʱ�ĸ��ڵ�
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
* ����һ�������ڵ������,ֵΪ-1��ʾû�к��ӽڵ�
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
