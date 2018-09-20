#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct TREE_NODE{
	struct TREE_NODE *pLeft;
	struct TREE_NODE *pRight;
	int value;
}ST_TREE_NODE;

/**
* @startPreOrder:ǰ�����������ʼ��
* @endPreOrder:ǰ�����������ֹ��
* @endInOrder:���������������ʼ��
* @endInOrder:�������������ֹ��
* ���ض��������
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
	* ǰ��������е��׸�Ԫ�ؼ�Ϊ���ڵ�
	**/
	pTreeNode->value = startPreOrder[0];
	pTreeNode->pLeft = NULL;
	pTreeNode->pRight = NULL;
	
	/**
	* �ݹ����
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
	* ������������ĸ��ڵ�,�Դ˷ֳ�������������
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
	* ����������
	**/
	if (length > 0)
	{
		pTreeNode->pLeft = Construct(startPreOrder+1, startPreOrder+length,
									startInOrder, startOrder - 1);
	}
	
	/**
	* ����������
	**/
	if (endInOrder - startOrder > 0)
	{
		pTreeNode->pRight = Construct(startPreOrder+length+1, endPreOrder,
									startOrder+1, endInOrder);
	}


	return pTreeNode;

}


/**
* ǰ�������һ���ڵ�Ϊ���ڵ���������ĸ��ڵ�
* �������,���ڵ㽫�Ὣ���зֳ���������
* �ݹ���������ֳ���������
**/
ST_TREE_NODE* BtreeConstruct(int *preOrder, int *inOrder, int length)
{
	if (NULL == preOrder || NULL == inOrder || 0 >= length)
	{
		return NULL;
	}
	
	return Construct(preOrder, preOrder+length-1, inOrder, inOrder+length-1);
}
