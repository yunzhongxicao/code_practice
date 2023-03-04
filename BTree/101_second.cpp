/*
@File  :101_second.cpp
@Author:dfc
@Date  :2023/3/4  10:38
@Desc  : ¶Ô³Æ¶þ²æÊ÷
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

bool traverse(TreeNode *left_node, TreeNode*right_node)
{
    if (!left_node and !right_node) return true;
    if (!left_node and right_node) return false;
    if (left_node and !right_node) return false;
    if (left_node->val != right_node->val) return false;
    bool flag1 = traverse(left_node->left,right_node->right);
    bool flag2 = traverse(left_node->right,right_node->left);
    return flag1 and flag2;
}

bool isSymmetric(TreeNode* root)
{
    if (!root) return true;
    return traverse(root->left,root->right);
}

