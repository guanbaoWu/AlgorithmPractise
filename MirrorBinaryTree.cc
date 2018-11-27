#include <iostream>
#include <string>

struct BinaryTreeNode
{
    double m_dbVaule;
    struct BinaryTreeNode* m_pLeft;
    struct BinaryTreeNode* m_pRight;
};

/**
* 给定一颗二叉树,要求输出该二叉树的镜像二叉树
* 解决思路：递归左右子节点,并交换其值
* 递归的结束条件：输入的二叉树为空
**/
class Solution
{
public:
    void MirrowBinaryTree(struct BinaryTreeNode* pTree)
    {
        if (NULL == pTree)
        {
            return;
        }
        
        /**
        * 交换左右子树
        **/
        struct BinaryTreeNode *pTemp = pATree->m_pLeft;
        pATree->m_pLeft = pATree->m_pRight;
        pATree->m_pRight = pTemp;
        
        /**
        * 继续递归交换左右子树的左右子树节点
        **/
        (void)MirrowBinaryTree(pATree->m_pLeft);
        (void)MirrowBinaryTree(pATree->m_pRight);
        
        return 0;
    }
};