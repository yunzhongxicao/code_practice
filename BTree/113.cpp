/*
@File  :113.cpp
@Author:dfc
@Date  :2022/10/13  11:42
@Desc  : Â·¾¶×ÜºÍ2
*/

#include "iostream"
#include "stack"
#include "vector"
#include "queue"
#include <numeric>

using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
public:
    TreeNode(){val=0;left=NULL;right=NULL;};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

vector<vector<int>> pathSum(TreeNode* root, int targetSum);
void traversal(TreeNode *p, vector<int> &path, vector<vector<int>> &result, int target,int &sum);

vector<vector<int>> pathSum(TreeNode* root, int targetSum)
{
    vector<vector<int>> result;
    vector<int> path;
    int sum = 0;
    if (!root) return result;
    traversal(root,path,result,targetSum,sum);
    return result;
}


void traversal(TreeNode *p, vector<int> &path, vector<vector<int>> &result, int target,int &sum)
{
    path.push_back(p->val);
    sum  =sum +p->val;

    if (p->left==NULL and p->right==NULL)
    {
        if (sum==target)
        {
            result.push_back(path);
        }
        return;
    }
    if (p->left)
    {
        traversal(p->left,path,result,target,sum);
        path.pop_back();
        sum = sum - p->left->val;
    }
    if (p->right)
    {
        traversal(p->right,path,result,target,sum);
        path.pop_back();
        sum = sum -p->right->val;
    }

}

