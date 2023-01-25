/*
@File  :offer_68_1.cpp
@Author:dfc
@Date  :2023/1/25  11:37
@Desc  : 二叉搜索树的最近公共祖先
*/
#include "iostream"

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){};
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    int min_value = min(p->val,q->val);
    int max_value = max(p->val,q->val);
    TreeNode *cur_node = root;
    while (true)
    {
        if (cur_node->val > max_value)
            cur_node = cur_node->left;
        else if (cur_node->val < min_value)
            cur_node = cur_node->right;
        else
            break;
    }
    return cur_node;

}

