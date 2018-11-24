#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct ListNode
{
    int m_nvalue;
    ListNode* m_pNext;
};

/**
* 给定两个分别单调递增的单向链表，要求合并这两个链表并且同样是单调递增的
* 解决思路：设置两个临时节点指针用于保存当前比较节点的下一节点，循环往复完成合并
**/

typedef int (*GenValue)(unsigned int);

int GenEven(unsigned int num)
{
    return num * 2;
}

int GenOdd(unsigned int num)
{
    return ((num * 2) + 1);
}

class Solution
{
public:
    int createList(struct ListNode *pHead, GenValue cb)
    {
        int i = 0;
        struct ListNode *Node = NULL;
        
        if (NULL == pHead)
        {
            return -1;
        }
        for(i=9; i>=0; i--)
        {
            Node = (struct ListNode *)malloc(sizeof(struct ListNode));
            if (Node != NULL)
            {
                if (cb)
                    Node->m_nvalue = cb(i);
                else
                    Node->m_nvalue = i;
                    
                Node->m_pNext = pHead->m_pNext;
                pHead->m_pNext = Node;
            }
  
        }
        
        return 0;
    }
    
    void printList(struct ListNode *pHead)
    {
        struct ListNode *Node = NULL;
        
        if (NULL == pHead)
        {
            return;
        }
        
        Node = pHead->m_pNext;
        while(Node)
        {
            printf("Node:%p,value:%d\n", Node, Node->m_nvalue);
            Node = Node->m_pNext;
        }
    }
    
    /**
    * 合并两个单调递增的单向链表,并返回合并后的头结点
    **/
    struct ListNode* MergeOrderList(struct ListNode *pHead1, struct ListNode *pHead2)
    {
        if (NULL == pHead1 || NULL == pHead1->m_pNext)
        {
            return pHead2;
        }
        else if(NULL == pHead2 || NULL == pHead2->m_pNext)
        {
            return pHead1;
        }
        
        /**
        * 建立两个指针,指向当前比较节点的下一节点
        **/
        struct ListNode *pHead = NULL;
        struct ListNode *pNode1 = pHead1->m_pNext;
        struct ListNode *pNode2 = pHead2->m_pNext;
        
        pNode1->m_nvalue < pNode2->m_nvalue ? pHead = pHead1 : pHead = pHead2;
        while(pNode1 != NULL && pNode2 != NULL)
        {
            struct ListNode *pTemp1 = pNode1->m_pNext;
            struct ListNode *pTemp2 = pNode2->m_pNext;
            
            if (pNode1->m_nvalue < pNode2->m_nvalue)
            {
                pNode1->m_pNext = pNode2;
                pNode1 = pTemp1;
            }
            else
            {
                pNode2->m_pNext = pNode1;
                pNode2 = pTemp2;
            }
        }
        
        return pHead;
    }    
};

int main()
{
    Solution s;
	struct ListNode stList1 = {-1, NULL};
    struct ListNode stList2 = {-1, NULL};
	
	if (0 != s.createList(&stList1, GenEven))
	{
		return -1;
	}
    
    if (0 != s.createList(&stList2, GenOdd))
	{
		return -1;
	}
	
    cout << "print stList1:" << endl;
	s.printList(&stList1);
    
    cout << "print stList2:" << endl;
    s.printList(&stList2);
    
    struct ListNode *pHead = s.MergeOrderList(&stList1, &stList2);
    
    if (NULL != pHead)
    {
        cout << "print MergeOrderList:" << endl;
        s.printList(pHead);
    }
	
	return 0;	
}
