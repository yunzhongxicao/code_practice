/*
@File  :112_second.cpp
@Author:dfc
@Date  :2023/3/6  11:22
@Desc  : 路径总和
*/

#include "iostream"
#include "stack"
#include "vector"
#include "queue"

using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
public:
    TreeNode(){val=0;left=NULL;right=NULL;};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

int sum=0;

bool backtracking(TreeNode *p, int targetSum)
{
    if (!p->left and !p->right) // 到叶子节点就结束
    {
        if (sum==targetSum)
            return true;
        return false;
    }
    if (p->left) // 这种写法就是每次进入这一层之前， 在上一层就把sum加进去了
    {
        sum += p->left->val;
        bool flag1 = backtracking(p->left, targetSum);
        sum -= p->left->val;
        if (flag1)
            return true;
    }
    if (p->right)
    {
        sum += p->right->val;
        bool flag2 = backtracking(p->right,targetSum);
        sum -= p->right->val;
        if (flag2)
            return true;
    }
    return false;
}

bool hasPathSum(TreeNode* root, int targetSum)
{
    if (!root) return false;
    sum += root->val;
    return backtracking(root, targetSum);
}
