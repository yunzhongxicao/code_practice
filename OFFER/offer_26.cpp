/*
@File  :offer_26.cpp
@Author:dfc
@Date  :2022/12/22  21:01
@Desc  : 树的子结构
*/
#include "iostream"
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
bool dp(TreeNode* t1, TreeNode* t2);

bool isSubStructure(TreeNode* A, TreeNode* B)
{
    if (A== nullptr or B == nullptr) return false;
    if (A->val and B->val and dp(A,B)) return true;
    return isSubStructure(A->left,B) or isSubStructure(A->right,B);
}

bool dp(TreeNode* t1, TreeNode* t2)// 这个函数的功能是判断 以A为头节点的二叉树是否 包含B，必须从A开始
{
    if (t2== nullptr) return true;
    if (t1== nullptr) return false;
    bool left,right;
    if (t1->val != t2->val)
    {
        return false;  // 如果不相等 直接就判断不包含
    }
    else
    {
        left = dp(t1->left,t2->left);
        right = dp(t1->right,t2->right);
    }
    return left and right;  // 既要a b 相等 也要左右子树相等

}

