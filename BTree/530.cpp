/*
@File  :530.cpp
@Author:dfc
@Date  :2022/10/14  21:42
@Desc  : 二叉搜索树的最小绝对差
*/

#include "iostream"
#include "stack"
#include "vector"
#include "queue"
#include "algorithm"

using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
public:
    TreeNode(){val=0;left=NULL;right=NULL;};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

TreeNode *last_node= nullptr;
int min_value=INT32_MAX;
void traverse(TreeNode *p);
int getMinimumDifference(TreeNode* root)
{
    if (!root) return 0;

    traverse(root);
    return min_value;

}

void traverse(TreeNode *p)
{
    if (!p) return;
    traverse(p->left);
    if (last_node)
    {
        int tmp = abs(p->val - last_node->val);
        min_value = tmp<= min_value?tmp:min_value;
    }
    last_node=p;

    traverse(p->right);

}