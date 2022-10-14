/*
@File  :700.cpp
@Author:dfc
@Date  :2022/10/14  11:46
@Desc  : 二叉搜索树中的搜索
*/


#include "iostream"
#include "stack"
#include "vector"
#include "queue"
#include "algorithm"

using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
public:
    TreeNode(){val=0;left=NULL;right=NULL;};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

TreeNode* searchBST(TreeNode* root, int val);

/* 递归法
TreeNode* searchBST(TreeNode* root, int val)
{
    if (!root) return nullptr;
    if (root->val == val) return root;
    TreeNode *left;
    TreeNode *right;
    if (root->val >val)
    {
        left =  searchBST(root->left,val);
    }
    else if (root->val <val)
    {
        right=searchBST(root->right,val);
    }
    if (left== nullptr and right== nullptr)
        return nullptr;
    else if (left!= nullptr)
        return left;
    else if (right!= nullptr)
        return right;
}
*/
/*
TreeNode* searchBST(TreeNode* root, int val)
{
    if (!root) return nullptr;
    if (root->val == val) return root;
    TreeNode *result;  // 因为二叉搜索树其实是有方向的 不是左 就是右 只会有一种情况，要么向左要么向右
                        // 所以不需要像上面那样定义两个返回节点 只需要一个结果就行
    if (root->val >val)
    {
        result =  searchBST(root->left,val);
    }
    else if (root->val <val)
    {
        result=searchBST(root->right,val);
    }
    return result;  // 这个返回值是可以一层层往上传回去的
}*/

TreeNode* searchBST(TreeNode* root, int val)
{
    TreeNode *p;
    if (!root) return nullptr;
    p = root;
    while (p!= nullptr)
    {
        if (p->val > val)
        {
            p= p->left;
        } else if (p->val < val)
        {
            p = p->right;
        } else
        {
            break;
        }
    }
    return p;
}
