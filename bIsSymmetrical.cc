#include <iostream>
#include <string>

using namespace std;

struct BinaryTreeNode
{
    double m_dbVaule;
    struct BinaryTreeNode* m_pLeft;
    struct BinaryTreeNode* m_pRight;
};

/**
* 给定一颗二叉树,判断该二叉树是否左右对称
* 实现原理:
* 1、前序遍历该二叉树,对于空的节点记为nullptr(根-左子树-右子树)
* 2、对称的前序遍历该二叉树,对于空的节点记为nullptr(根-右子树-左子树)
* 3、如果两种遍历方式相等,则表明该二叉树是对称的
**/
class Solution
{
public:
    bool bIsSymmetrical(struct BinaryTreeNode *pRoot1, struct BinaryTreeNode *pRoot2)
    {
        if (NULL == pRoot1 && NULL == pRoot2)
            return true;
            
        if ((NULL == pRoot1 && NULL != pRoot2)
            || (NULL != pRoot1 && NULL == pRoot2))
            return false;
        
        if (pRoot1->m_dbVaule != pRoot2->m_dbVaule)
            return false;
            
        return bIsSymmetrical(pRoot1->m_pLeft, pRoot2->m_pRight)
                && bIsSymmetrical(pRoot1->m_pRight, pRoot2->m_pLeft);
    }
    ppi
    bool bIsSymmetrical(struct BinaryTreeNode *pTree)
    {
        if (NULL == pTree)
            return false;
            
        return bIsSymmetrical(pTree, pTree);
    }
};