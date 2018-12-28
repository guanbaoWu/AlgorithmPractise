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
* 问题：输入一个二叉树的根节点，计算该二叉树的深度(树的深度：从根开始计算，包含根，直到最远叶子节点的层数)
* 实现原理:
* 1、最大深度：通过递归的方式，分别计算各子树的深度，最后合并得到深度最深的子树则子树深度即为二叉树的深度
* 2、如果只存在左右子树其中一个时，最小深度即为存在的子树深度，如果左右子树都存在，则最小深度为两者之间最小的
**/

typedef struct TREE_NODE{
	struct TREE_NODE *pLeft;
	struct TREE_NODE *pRight;
	int value;
}ST_TREE_NODE;

class Solution
{
public:
    int maxDepthTree(ST_TREE_NODE *pRoot)
    {
        int LeftDepth = 0;
        int RightDepth = 0;
        
        if (pRoot == NULL)
        {
            return 0;
        }
        
        /**
        * 只有根节点的树的深度为1
        **/
        LeftDepth = maxDepthTree(pRoot->pLeft) + 1;
        RightDepth = maxDepthTree(pRoot->pRight) + 1;
        
        return LeftDepth > RightDepth ? LeftDepth : RightDepth;
        
    }
    
    int minDepthTree(ST_TREE_NODE *pRoot)
    {
        int LeftDepth = 0;
        int RightDepth = 0;
        
        if (pRoot == NULL)
        {
            return 0;
        }
        
        /**
        * 只有左子树或者右子树,最大深度为某一子树的深度
        **/
        if (pRoot->pLeft != NULL && pRoot->pRight == NULL)
        {
            LeftDepth = minDepthTree(pRoot->pLeft) + 1;
        }
        else if (pRoot->pRight != NULL && pRoot->pLeft == NULL)
        {
            RightDepth = minDepthTree(pRoot->pRight) + 1;
        }
        else
        {
            /**
            * 左右子树都存在
            **/
            LeftDepth = minDepthTree(pRoot->pLeft) + 1;
            RightDepth = minDepthTree(pRoot->pRight) + 1;
        }
        
        return LeftDepth < RightDepth ? LeftDepth : RightDepth;
        
    }
};
