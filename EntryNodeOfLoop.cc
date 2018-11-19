#include <iostream>
#include <string>

using namespace std;

struct ListNode
{
    int m_nvalue;
    ListNode* m_pNext;
};

/**
* 给定一个单向不循环链表,判断该链表是否存在,如果存在,请找出环的入口节点
* 解决思路：采用双指针的方式
* 1、判断链表是否有环:第一指针每次移动一个节点,第二指针一次移动两个节点,当第二节点追上第一节点时,则有环
* 2、查找环的入口:先获取环的节点数,再将第二指针移动环的节点数的次数,此时同时移动第一第二节点,当节点相遇即为环的入口
**/

class Solution
{
public:
    int createLoopList(struct ListNode *pHead)
    {
        int i = 0;
        struct ListNode *Node = NULL;
        
        if (NULL == pHead)
        {
            return -1;
        }
        
        int loopentry = 0;
        
        cout << "please input entry([0-9]):" << endl;
        cin >> loopentry;
        
        struct ListNode *tail = NULL;
        struct ListNode *loop = NULL;
        for(i=9; i>=0; i--)
        {
            Node = (struct ListNode *)malloc(sizeof(struct ListNode));
            if (Node != NULL)
            {
                Node->m_nvalue = i;
                Node->m_pNext = pHead->m_pNext;
                pHead->m_pNext = Node;
            }
            
            if (i == 9)
            {
                tail = Node;
            }
            
            if (i == loopentry)
            {
                loop = Node;
            }
        }
        
        if (NULL != tail && NULL != loop)
        {
            tail->m_pNext = loop;
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
    * 节点是否有环,存在则返回环中的节点
    **/
    struct ListNode* isListLoop(struct ListNode *pListpHead)
    {
        struct ListNode *pAhead = NULL;
        struct ListNode *pBehind = NULL;
        
        if (NULL == pListpHead || NULL == pListpHead->m_pNext)
        {
            return NULL;
        }
        
        /**
        * 第一指针以一个节点的速度移动,第二指针以两个节点的速度移动
        **/
        pAhead = pListpHead->m_pNext;
        pBehind = pAhead->m_pNext;
        while(NULL != pAhead && NULL != pBehind)
        {
            if (pAhead == pBehind)
                return pBehind;
                
            if ((pBehind = pBehind->m_pNext) != NULL)
            {
                pBehind = pBehind->m_pNext;
            }
            
            pAhead = pAhead->m_pNext;
            
        }
        
        return NULL;
        
    }
    
    /**
    * 返回存在环的链表的入口节点
    **/
    struct ListNode* entryNodeOfLoop(struct ListNode *pListpHead)
    {
        struct ListNode *pLoopNode = isListLoop(pListpHead);
        if (NULL == pLoopNode)
        {
            return NULL;
        }
        
        /**
        * 计算环的大小
        **/
        struct ListNode *pLoop = pLoopNode;
        unsigned int loop = 1;
        while(pLoopNode->m_pNext != pLoop)
        {
            pLoopNode = pLoopNode->m_pNext;
            ++loop;
        }
        
        
        /**
        * 第二指针首先移动等于环数的节点数后,两指针以一节点的移动速度同时移动
        **/
        struct ListNode *pAhead = pListpHead->m_pNext;
        struct ListNode *pBehind = pListpHead->m_pNext;
        while(loop--)
        {
            if (NULL == pBehind)
            {
                return NULL;
            }
            
            pBehind = pBehind->m_pNext;
        }
        
        
        while(NULL != pAhead && NULL != pBehind)
        {
            if (pAhead == pBehind)
            {
                return pBehind;
            }
            
            pAhead = pAhead->m_pNext;
            pBehind = pBehind->m_pNext;
            
        }
        
        return NULL;
    }
    
};

int main()
{
    Solution s;
	struct ListNode stList = {-1, NULL};
	
	if (0 != s.createLoopList(&stList))
	{
		return -1;
	}
	
	//s.printList(&stList);
    
    struct ListNode *pNode = s.entryNodeOfLoop(&stList);
    
    if (NULL != pNode)
    {
        printf("entryNodeOfLoop, Node:%p,value:%d\n", pNode, pNode->m_nvalue);
    }
	
	return 0;
	
}