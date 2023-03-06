/*
@File  :404_second.cpp
@Author:dfc
@Date  :2023/3/6  10:31
@Desc  : 左叶子之和
*/
#include "iostream"
#include "stack"
#include "vector"

using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
public:
    TreeNode(){val=0;left=NULL;right=NULL;};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

int result=0;

void traverse(TreeNode *p)
{
    if (!p) return;
    if (p->left and !p->left->left and !p->left->right) // 这就是找左叶子的逻辑 其实是找左叶子的父节点
    {
        result += p->left->val;
    }
    traverse(p->left);
    traverse(p->right);
}

int sumOfLeftLeaves(TreeNode* root)
{
    traverse(root);
    return result;
}



