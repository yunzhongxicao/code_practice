/*
@File  :offer_2_051.cpp
@Author:dfc
@Date  :2023/7/5  20:11
@Desc  :
*/
#include "iostream"

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){};
};

int  sum=0;
int result=INT32_MIN;

int dfs(TreeNode *root)
{
    if (!root) return 0;
    int left_value = max(dfs(root->left),0);
    int right_value = max(dfs(root->right),0);
    result = max(result, root->val+left_value+right_value);
    return root->val + max(left_value,right_value);
}

int maxPathSum(TreeNode* root)
{
    dfs(root);
    return result;
}

