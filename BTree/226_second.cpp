/*
@File  :226_second.cpp
@Author:dfc
@Date  :2023/3/4  10:22
@Desc  : ·­×ª¶þ²æÊ÷
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

void traverse(TreeNode *p)
{
    if (!p) return;
    traverse(p->left);
    traverse(p->right);
    TreeNode *temp = p->left;
    p->left = p->right;
    p->right = temp;
}

TreeNode* invertTree(TreeNode* root)
{
    traverse(root);
    return root;
}

