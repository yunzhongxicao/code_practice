/*
@File  :637_second.cpp
@Author:dfc
@Date  :2023/3/2  10:53
@Desc  : 二叉树的层平均值
*/
#include "iostream"
#include "vector"
#include "queue"
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){};
};

vector<double> averageOfLevels(TreeNode* root)
{
    vector<double> result;
    queue<TreeNode *> my_queue;
    if (!root) return result;
    my_queue.push(root);
    while (!my_queue.empty())
    {
        int count =0;
        double value = 0;
        int size = my_queue.size();
        for (int i = 0; i < size    ; ++i) {
            TreeNode * temp = my_queue.front();
            my_queue.pop();
            count++;
            value += temp->val;
            if (temp->left) my_queue.push(temp->left);
            if (temp->right) my_queue.push(temp->right);
        }
        result.push_back(value/count);
    }
    return result;
}


