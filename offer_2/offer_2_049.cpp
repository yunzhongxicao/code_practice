/*
@File  :offer_2_049.cpp
@Author:dfc
@Date  :2023/5/16  18:19
@Desc  :
*/
#include "iostream"
#include "vector"
#include "string"

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){};
};

string path;
int  result=0;

void backtracking(TreeNode *root)
{
    path.push_back('0'+root->val);
    if (root->left== nullptr and root->right== nullptr)
    {
        result += stoi(path);
        return;
    }
    if (root->left)
    {
        backtracking(root->left);
        path.pop_back();
    }
    if (root->right)
    {
        backtracking(root->right);
        path.pop_back();
    }
}


int sumNumbers(TreeNode* root)
{
    if (!root) return result;
    backtracking(root);
    return result;
}