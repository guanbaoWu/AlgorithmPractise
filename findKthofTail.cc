#include <iostream>
#include <string>

using namespace std;

struct ListNode
{
    int m_nvalue;
    ListNode* m_pNext;
};

/**
* 给定一个单向不循环链表,输出该链表中倒数第K个节点,从1开始计数,即倒数第一个节点即为尾节点
* 解决思路：采用双指针的方式
* 1、第一第二指针指向第一个节点
* 2、第二指针移动K个节点
* 3、移动第一指针,第二指针,当第二指针移动到尾节点时,第一指针指向的节点即为倒数第K个节点
**/

class Solution
{
public:
    int createList(struct ListNode *pHead)
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
    
    struct ListNode* findKthofTail(struct ListNode *pListpHead, unsigned int k)
    {
        struct ListNode *pAhead = pListpHead;
        struct ListNode *pBehind = NULL;
        
        if (NULL == pListpHead || NULL == pListpHead->m_pNext || k == 0)
        {
            return NULL;
        }
        
        /**
        * 移动指针K次
        **/
        for (unsigned int i = 0; i < k; ++i)
        {
            pAhead = pAhead->m_pNext;
            if (NULL == pAhead)
            {
                /**
                * 节点不足K个,返回空
                **/
                return NULL;
            }
        }
        
        pBehind = pListpHead->m_pNext;
        while(pAhead->m_pNext)
        {
            pAhead = pAhead->m_pNext;
            pBehind = pBehind->m_pNext;
        }
        
        return pBehind;
        
    }
    
};

int main()
{
    Solution s;
	struct ListNode stList = {-1, NULL};
	
	if (0 != s.createList(&stList))
	{
		return -1;
	}
	
	s.printList(&stList);
    
    unsigned int k;
    
    cout << "input K:" << endl;
    cin >> k;
	
    struct ListNode *pKNode = s.findKthofTail(&stList, k);
    
    if (NULL != pKNode)
    {
        printf("findKthofTail k = %d, Node:%p,value:%d\n", k, pKNode, pKNode->m_nvalue);
    }
	
	return 0;
	
}