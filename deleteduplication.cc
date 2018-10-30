#include <iostream>

using namespace std;

struct ListNode
{
    int m_nvalue;
    ListNode* m_pNext;
};

/**
* 删除有序链表中的重复节点
**/
class Solution
{
public:
    void deleteduplication(struct ListNode **pHead)
    {
        if (NULL == pHead || NULL == *pHead)
        {
            return;
        }
        
        struct ListNode *pPrvNode = NULL;
        struct ListNode *pNode = *pHead;
        
        while(pNode)
        {
            struct ListNode *pNext = pNode->m_pNext;
            
            /**
            * 存在重复的节点
            **/
            if (NULL != pNext && pNext->m_nvalue == pNode->m_nvalue)
            {
                struct ListNode *pDelete = pNode;
                int value = pNode->m_nvalue;
                
                while(pDelete != NULL && pDelete->m_nvalue == value)
                {
                    pNext = pDelete->m_pNext;
                    
                    delete pDelete;
                    
                    pDelete = pNext;
                }
                
                /**
                * 删除的是头结点
                **/
                if (pPrvNode == NULL)
                    *pHead = pNext;
                else
                    pPrvNode->m_pNext = pNext;
                
                pNode = pNext;
            }
            else
            {
                pPrvNode = pNode;
                pNode = pNode->m_pNext;
            }
            
        }  
    }
};
