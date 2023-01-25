/*
@File  :offer_68_2.cpp
@Author:dfc
@Date  :2023/1/25  12:56
@Desc  : 二叉树的公共祖先
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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (root== nullptr or root==p or root == q) return root;
    TreeNode *left_node = lowestCommonAncestor(root->left,p,q);
    TreeNode *right_node = lowestCommonAncestor(root->right,p,q);
    if (left_node and right_node) return root;
    if (left_node != nullptr) return left_node;
    if (right_node != nullptr) return right_node;
    return nullptr; // 不会到这一步的
}

