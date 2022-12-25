/*
@File  :offer_34.cpp
@Author:dfc
@Date  :2022/12/25  16:03
@Desc  : 二叉树中和为某一值的路径
*/
#include "vector"
#include "iostream"
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void backtracking(TreeNode *p, int target);
vector<int>path;
vector<vector<int>>result;
int sum;
vector<vector<int>> pathSum(TreeNode* root, int target)
{
    if(!root) return result;
    sum = root->val;
    path.push_back(sum);
    backtracking(root,target);
    return result;
}

void backtracking(TreeNode *p, int target) // sum记录的进入p这一层的节点后的和
{
    if (p->left== nullptr and p->right== nullptr) // 注意 此时叶子节点没有在后面进行计算了  所以要在上一层计算掉
    {
        if (sum==target) result.push_back(path);
        return;
    }
    if (p->left)
    {
        sum += p->left->val;
        path.push_back(p->left->val);
        backtracking(p->left, target);
        sum -= p->left->val;
        path.pop_back();
    }
    if (p->right)
    {
        sum += p->right->val;
        path.push_back(p->right->val);
        backtracking(p->right,target);
        sum -= p->right->val;
        path.pop_back();
    }
}