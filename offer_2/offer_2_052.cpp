/*
@File  :offer_2_052.cpp
@Author:dfc
@Date  :2023/7/6  23:20
@Desc  :
*/
#include "iostream"

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){};
};
TreeNode *pre;
void dfs(TreeNode *root)
{
    if (!root) return;
    dfs(root->left);
    root->left = nullptr; // 每次处理的是当前节点
    pre->right = root;
    pre = root;
    dfs(root->right);
}

TreeNode* increasingBST(TreeNode* root)
{
    TreeNode *head = new TreeNode(-1);
    pre=  head;
    dfs(root);
    return head->right;
}

