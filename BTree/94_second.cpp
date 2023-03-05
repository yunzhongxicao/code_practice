/*
@File  :94_second.cpp
@Author:dfc
@Date  :2023/2/28  11:59
@Desc  : 二叉树的中序遍历
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

vector<int> result;

void traverse(TreeNode *p)
{
    if (!p) return;
    traverse(p->left);
    result.push_back(p->val);
    traverse(p->right)  ;
}

/*vector<int> inorderTraversal(TreeNode* root)// 递归写法
{
    traverse(root);
    return result;
}*/

vector<int> inorderTraversal(TreeNode* root)
{
    stack<TreeNode * > my_stack1;
    stack<int> my_stack2;
    if (!root) return result;
    my_stack1.push(root);
    my_stack2.push(0);
    while (!my_stack1.empty())
    {
        if (my_stack2.top()==0)
        {
            my_stack2.top()=1;
            if (my_stack1.top()->left)
            {
                my_stack1.push(my_stack1.top()->left);
                my_stack2.push(0);
            }
        }
        else if (my_stack2.top()==1)
        {
            TreeNode *temp = my_stack1.top();
            result.push_back(temp->val);
            my_stack1.pop();
            my_stack2.pop();
            if (temp->right)
            {
                my_stack1.push(temp->right);
                my_stack2.push(0);
            }
        }
    }
    return result;
}



