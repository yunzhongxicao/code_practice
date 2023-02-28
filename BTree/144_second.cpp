/*
@File  :144_second.cpp
@Author:dfc
@Date  :2023/2/28  11:01
@Desc  :
*/
#include "iostream"
#include "vector"
#include "stack"
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){};
};
vector<int>  result;
void traverse(TreeNode *p)
{
    if (p== nullptr) return;
    result.push_back(p->val);
    traverse(p->left);
    traverse(p->right);
}

/*
vector<int> preorderTraversal(TreeNode* root)  // µ›πÈÀ„∑®
{
    traverse(root);
    return result;
}*/

vector<int> preorderTraversal(TreeNode* root)
{
    stack<TreeNode *> my_stack;
    if (!root) return result;
    TreeNode *p;
    my_stack.push(root);
    while (!my_stack.empty())
    {
        p = my_stack.top();
        my_stack.pop();
        result.push_back(p->val);
        if (p->right)
            my_stack.push(p->right);
        if (p->left )
            my_stack.push(p->left);
    }
    return result;
}
