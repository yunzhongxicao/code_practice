/*
@File  :113_second.cpp
@Author:dfc
@Date  :2023/3/6  14:25
@Desc  : Â·¾¶×ÜºÍ2
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

vector<int> path;
vector<vector<int>> result;
int sum=0;

void backtracking(TreeNode *p, int targetSum)
{
    sum += p->val;
    path.push_back(p->val);
    if (!p->left and !p->right)
    {
        if (sum==targetSum)
            result.push_back(path);
        return;
    }
    if (p->left)
    {
        backtracking(p->left,targetSum);
        sum -= p->left->val;
        path.pop_back();
    }
    if (p->right)
    {
        backtracking(p->right,targetSum);
        sum-=p->right->val;
        path.pop_back();
    }
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum)
{
    if (!root) return result;
    backtracking(root,targetSum);
    return result;
}

