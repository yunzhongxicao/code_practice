/*
@File  :offer_32_2.cpp
@Author:dfc
@Date  :2022/12/24  23:40
@Desc  : 从上到下打印二叉树2
*/
#include "iostream"
#include "vector"
#include "queue"
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>>result;
    if (!root) return result;
    queue<TreeNode*> my_queue;
    my_queue.push(root);
    TreeNode *p;
    while (!my_queue.empty())
    {
        int size = my_queue.size();
        vector<int> val;
        for (int i = 0; i < size; ++i) {
            p= my_queue.front();
            val.push_back(p->val);
            my_queue.pop();
            if(p->left) my_queue.push(p->left);
            if (p->right) my_queue.push(p->right);
        }
        result.push_back(val);
    }
    return result;
}
