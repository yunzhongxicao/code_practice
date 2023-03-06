/*
@File  :112_second.cpp
@Author:dfc
@Date  :2023/3/6  11:22
@Desc  : ·���ܺ�
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
    if (!p->left and !p->right) // ��Ҷ�ӽڵ�ͽ���
    {
        if (sum==targetSum)
            return true;
        return false;
    }
    if (p->left) // ����д������ÿ�ν�����һ��֮ǰ�� ����һ��Ͱ�sum�ӽ�ȥ��
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
