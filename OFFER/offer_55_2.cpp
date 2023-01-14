/*
@File  :offer_55-2.cpp
@Author:dfc
@Date  :2023/1/14  21:32
@Desc  : 平衡二叉树
*/
#include "iostream"
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL),right(NULL){}
};
int get_depth(TreeNode *p);
bool isBalanced(TreeNode* root)
{
    int result = get_depth(root);
    return result!=-1;
}

/*int get_depth(TreeNode *p)
{
    if (!p) return 0;
    int left_depth = get_depth(p->left);
    int right_depth = get_depth(p->right);
    if (left_depth==-1 or right_depth==-1) return -1;
    if (abs(left_depth-right_depth)>1) return -1;
    return max(left_depth,right_depth)+1;
}*/

int get_depth(TreeNode *p) // 优化一下
{
    if (!p) return 0;
    int left_depth = get_depth(p->left);
    if (left_depth==-1) return -1;
    int right_depth = get_depth(p->right);
    if (right_depth==-1) return -1;
    if (abs(left_depth-right_depth)>1) return -1;
    return max(left_depth,right_depth)+1;
}

