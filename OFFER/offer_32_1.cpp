/*
@File  :offer_32_1
@Author:dfc
@Date  :2022/12/24  21:13
@Desc  : 从上到下打印二叉树
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

vector<int> levelOrder(TreeNode* root)
{
    vector<int> result;
    if (!root) return result;
    TreeNode *p = root;
    queue<TreeNode*> my_queue;
    my_queue.push(p);
    while (!my_queue.empty())
    {
        p = my_queue.front();
        result.push_back(p->val);
        my_queue.pop();
        if (p->left) my_queue.push(p->left);
        if (p->right) my_queue.push(p->right);
    }
    return result;
}
