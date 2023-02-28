/*
@File  :145_second.cpp
@Author:dfc
@Date  :2023/2/28  18:15
@Desc  : 后序遍历
*/
#include "iostream"
#include "stack"
#include "vector"

using namespace std;

struct TreeNode{
    int  val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr), right(nullptr){};
};

vector<int> result;
void traverse(TreeNode *p)
{
    if (!p) return;
    traverse(p->left);
    traverse(p->right);
    result.push_back(p->val);
}

/*vector<int> postorderTraversal(TreeNode* root) // 递归的写法
{
    traverse(root);
    return result;
}*/

vector<int> postorderTraversal(TreeNode* root)
{
    stack<TreeNode *> my_stack1;
    stack<int> my_stack2;
    if (!root) return result;
    my_stack1.push(root);
    my_stack2.push(0);
    while (!my_stack1.empty())
    {
        if (my_stack2.top()==0)
        {
            my_stack2.top()=1;
            TreeNode *temp = my_stack1.top();
            if (temp->right)
            {
                my_stack1.push(temp->right);
                my_stack2.push(0);
            }
            if (temp->left)
            {
                my_stack1.push(temp->left);
                my_stack2.push(0);
            }
        }
        else if (my_stack2.top()==1)
        {
            result.push_back(my_stack1.top()->val);
            my_stack1.pop();
            my_stack2.pop();
        }
    }
    return result;
}


