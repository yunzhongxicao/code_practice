/*
@File  :102_second.cpp
@Author:dfc
@Date  :2023/2/28  18:41
@Desc  : ¶þ²æÊ÷µÄ²ãÐò±éÀú
*/
#include "iostream"
#include "vector"
#include "queue"
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){};
};

vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>>  result;
    queue<TreeNode *> my_queue;
    if (!root) return result;
    my_queue.push(root);
    while (!my_queue.empty())
    {
        vector<int> path;
        int size = my_queue.size();
        for (int i = 0; i < size; ++i) {
            TreeNode *temp = my_queue.front();
            path.push_back(temp->val);
            my_queue.pop();
            if (temp->left) my_queue.push(temp->left);
            if (temp->right) my_queue.push(temp->right);
        }
        result.push_back(path);
    }
    return result;
}

