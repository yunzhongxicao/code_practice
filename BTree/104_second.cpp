/*
@File  :104_second.cpp
@Author:dfc
@Date  :2023/3/4  11:20
@Desc  :
*/
#include "iostream"
#include "vector"

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){};
};

/*int maxDepth(TreeNode* root)
{
    if (!root) return 0;
    return 1+max(maxDepth(root->left), maxDepth(root->right));
}*/

int depth=0;
int result =0;

void backtracking(TreeNode *p)
{
    if (!p) {
        result = max(result, depth) ;
        return;
    }
    depth++;
    backtracking(p->left);
    depth--;
    depth++;
    backtracking(p->right);
    depth--;
}

int maxDepth(TreeNode* root)
{
    backtracking(root);
    return result;
}


