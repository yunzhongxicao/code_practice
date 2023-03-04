/*
@File  :111_second.cpp
@Author:dfc
@Date  :2023/3/4  14:09
@Desc  : 二叉树的最小深度
*/
#include "iostream"
#include "vector"

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){};
};

int minDepth(TreeNode* root)
{
    if (!root) return 0;
    int left_depth=INT32_MAX,right_depth=INT32_MAX;
    if (root->left and !root->right )
        left_depth = minDepth(root->left);
    else if (!root->left and root->right)
        right_depth = minDepth(root->right);
    else
    {
        left_depth = minDepth(root->left);
        right_depth = minDepth(root->right);
    }
    return min(left_depth,right_depth)+1;
}

