/*
@File  :offer_54.cpp
@Author:dfc
@Date  :2023/1/14  20:55
@Desc  :二叉搜索树的第k大节点
*/
#include "iostream"
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr),right(nullptr){}
};
int count=0;
TreeNode *result_node;
void traverse(TreeNode *p, int k);
int kthLargest(TreeNode* root, int k)
{
    traverse(root,k);
    return result_node->val;
}

void traverse(TreeNode *p, int k)
{
    if (!p) return;
    traverse(p->right,k);
    count++;
    if (count==k)
    {
        result_node = p;
        return;
    }
    traverse(p->left,k);
}