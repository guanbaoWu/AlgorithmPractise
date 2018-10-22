#include <iostream>

using namespace std;

struct ListNode
{
    int m_nvalue;
    ListNode* m_pNext;
};

/**
* O(1)时间内删除一个单链表节点
**/
class Solution
{
public:

    void DelListNodeOfO1(struct ListNode** pHead, struct ListNode* pDelNode)
    {
        if (NULL == pHead || NULL == pDelNode)
        {
            return;
        }
        
        /**
        * 只有一个节点
        **/
        if (pDelNode == *pHead)
        {
            *pHead = NULL;
        }
        else
        {
            /**
            * 非头结点,直接将下一个节点内容复制到待删除的节点,然后删除下一节点
            **/
            struct ListNode* pNode = pDelNode->m_pNext;
            if (NULL == pNode)
            {
                /**
                * 尾节点只能遍历删除
                **/
                struct ListNode* pNodeTemp = *pHead;
                while(pNodeTemp->m_pNext != pDelNode)
                {
                    pNodeTemp = pDelNode->m_pNext;
                }
                
                if (NULL != pNodeTemp)
                {
                    pNodeTemp->m_pNext = NULL;
                }
                
            }
            else
            {
                pDelNode->m_pNext = pNode->m_pNext;
                pDelNode->m_nvalue = pNode->m_nvalue;  
                pDelNode = pNode;
            }
                    
        }
            
        delete pDelNode;
        
        return;
        
    }
};

