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
        struct BinaryTreeNode *pTemp = pTree->m_pLeft;
        pTree->m_pLeft = pTree->m_pRight;
        pTree->m_pRight = pTemp;
        
        /**
        * 继续递归交换左右子树的左右子树节点
        **/
        MirrowBinaryTree(pTree->m_pLeft);
        MirrowBinaryTree(pTree->m_pRight);
    }
};

int main()
{
    Solution s;
    
    s.MirrowBinaryTree(NULL);
    
    return 0;
}