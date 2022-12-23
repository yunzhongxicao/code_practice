/*
@File  :offer_28.cpp
@Author:dfc
@Date  :2022/12/23  11:57
@Desc  : 对称的二叉树
*/
#include "iostream"
#include "queue"
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool isSymmetric_2_tree(TreeNode* t1, TreeNode* t2);

bool isSymmetric(TreeNode* root)
{
    if (!root) return true;
    return isSymmetric_2_tree(root->left,root->right);
}

bool isSymmetric_2_tree(TreeNode* t1, TreeNode* t2)  // 判断传入的两个树是否镜像
{
    if (t1== nullptr and t2  == nullptr) return true;
    if (t1== nullptr or t2== nullptr)  return false;
    if (t1->val != t2->val)  return false;
    bool flag1 = isSymmetric_2_tree(t1->left,t2->right);
    bool flag2 = isSymmetric_2_tree(t1->right,t2->left);
    return flag1 and flag2;
}

