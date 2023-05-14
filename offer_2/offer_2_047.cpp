/*
@File  :offer_2_047.cpp
@Author:dfc
@Date  :2023/5/11  8:44
@Desc  :
*/
#include "iostream"
#include "vector"
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){};
};

bool traverse(TreeNode *root)
{
    if (!root) return true;
    bool flag1 = traverse(root->left);
    if (flag1)
        root->left = nullptr;
    bool flag2 = traverse(root->right);
    if (flag2)
        root->right = nullptr;
    if(flag1 and flag2 and root->val==0) return true;
    else return false;
}

TreeNode* pruneTree(TreeNode* root)
{
    if (!root) return root;
    bool flag = traverse(root);
    if (flag) return nullptr;
    return root;
}

