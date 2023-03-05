/*
@File  :257_second.cpp
@Author:dfc
@Date  :2023/3/5  16:28
@Desc  : 二叉树的所有路径
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

vector<int> path;
vector<string > result;

void backtracking(TreeNode *p)
{
    if (!p->left and !p->right)
    {
        string  temp="";
        temp += to_string(path[0]);
        for (int i = 1; i < path.size(); ++i) {
            temp += ("->"+to_string(path[i]));
        }
        result.push_back(temp);
        return;
    }
    if (p->left)
    {
        path.push_back(p->left->val);
        backtracking(p->left);
        path.pop_back();
    }
    if (p->right)
    {
        path.push_back(p->right->val);
        backtracking(p->right);
        path.pop_back();
    }
}

vector<string> binaryTreePaths(TreeNode* root)
{
    if (!root) return result;
    path.push_back(root->val);
    backtracking(root);
    return result;
}

