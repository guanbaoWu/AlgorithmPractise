#include <iostream>
#include <string>

struct BinaryTreeNode
{
    double m_dbVaule;
    struct BinaryTreeNode* m_pLeft;
    struct BinaryTreeNode* m_pRight;
};

/**
* 输入两节二叉树A和B,判断B是不是A的子结构
* 解决思路：递归比较
* 1、比较两个二叉树的根节点,相同,则继续比较递归左右子树的根
* 2、相同,则继续比较递归左右子树的根
* 3、不相同,递归比较A的左右子树和B
**/
#define UTMOST_PERCISION 0.00000001

class Solution
{
public:
    bool Equal(double v1, double v2)
    {
        if (v1 - v2 > -UTMOST_PERCISION && v1 - v2 < UTMOST_PERCISION)
        {
            return true;
        }
        
        return false;
    }
    
    bool IsTreeBOnTreeA(struct BinaryTreeNode *pATree, struct BinaryTreeNode* pBTree)
    {
    
        if (NULL == pBTree)
            return true;
        if (NULL == pATree)
            return false;
        
        if (Equal(pATree->m_dbVaule, pBTree->m_dbVaule))
        {
            return (IsTreeBOnTreeA(pATree->m_pLeft, pBTree->m_pLeft) 
                    && IsTreeBOnTreeA(pATree->m_pRight, pBTree->m_pRight));
        }
        
        return false;
    }
    
    bool IsSubTree(struct BinaryTreeNode *pATree, struct BinaryTreeNode* pBTree)
    {
        bool result = false;
        
        if (NULL == pATree || NULL == pBTree)
        {
            return false;
        }
        
        /**
        * 判断根节点是否相同
        **/
        if (Equal(pATree->m_dbVaule, pBTree->m_dbVaule))
        {
            /**
            * 根节点相同,继续判断左右子树是否相同
            **/
            result = IsTreeBOnTreeA(pATree, pBTree);
        }
        
        /**
        * 根节点不相同,判断是否是归属于左子树
        **/
        if (!result)
            result = IsSubTree(pATree->m_pLeft, pBTree);
        
        /**
        * 不属于左子树,则继续查找右子树
        **/
        if (!result)
            result = IsSubTree(pATree->m_pRight, pBTree);
            
        return result;
    }
};

int main()
{
    Solution s;
    
    s.IsSubTree(NULL, NULL);
    
    return 0;
}