/*
@File  :112.cpp
@Author:dfc
@Date  :2022/10/13  11:21
@Desc  :Â·¾¶×ÜºÍ
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

bool hasPathSum(TreeNode* root, int targetSum);
void traversal(TreeNode *p,int target,int &sum,bool &result);

bool hasPathSum(TreeNode* root, int targetSum)
{
    int sum = 0;
    bool result = false;
    if (!root) return false;
    traversal(root,targetSum,sum,result);
    return result;
}

void traversal(TreeNode *p,int target,int &sum,bool &result)
{
    sum = sum+ p->val;
    if (p->right==NULL and p->left==NULL)
    {
        if (sum == target)
            result = true;
        return;
    }

    if (p->left)
    {
        traversal(p->left,target,sum,result);
        sum = sum-p->left->val;
    }
    if (p->right)
    {
        traversal(p->right,target,sum,result);
        sum = sum -p->right->val;
    }

}
