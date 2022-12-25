/*
@File  :offer_32_3.cpp
@Author:dfc
@Date  :2022/12/25  8:34
@Desc  : 从上到下打印二叉树3
*/
#include "iostream"
#include "vector"
#include "queue"
#include "stack"
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<vector<int>> levelOrder(TreeNode* root) // 其实从第二行到第三行 第二行谁先弹出去  它的子孙就会先进来 但是第三行会后出  符合栈的特性
{
    vector<vector<int>> result;
    stack<TreeNode*>my_stack,my_stack2; // 如果是一个栈的话 边pop边push不行   因为后进先出
    if (!root) return result;
    my_stack.push(root);
    TreeNode *p;
    int level = 1;
    while (!my_stack.empty())
    {
        int size = my_stack.size();
        vector<int> val;

        while (!my_stack.empty()){
            p = my_stack.top();
            val.push_back(p->val);
            my_stack.pop();
            if ((level&1)==1)
            {
                if (p->left) my_stack2.push(p->left);
                if (p->right) my_stack2.push(p->right);
            }
            else
            {
                if (p->right) my_stack2.push(p->right);
                if (p->left) my_stack2.push(p->left);
            }
        }
        my_stack = my_stack2;
        while (!my_stack2.empty())
        {
            my_stack2.pop();
        }
        result.push_back(val);
        level++;
    }
    return result;
}

