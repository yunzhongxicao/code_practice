/*
@File  :107_second.cpp
@Author:dfc
@Date  :2023/3/2  10:28
@Desc  : ¶þ²æÊ÷ µÄ²ãÐò±éÀú2
*/
#include "iostream"
#include "vector"
#include "queue"
#include "algorithm"
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){};
};

vector<vector<int>> levelOrderBottom(TreeNode* root)
{
    queue<TreeNode *>my_queue;
    vector<vector<int>> result;
    if (!root) return result;
    my_queue.push(root);
    while (!my_queue.empty())
    {
        int size = my_queue.size();
        vector<int> path;
        for (int i = 0; i < size; ++i) {
            TreeNode *temp = my_queue.front();
            my_queue.pop();
            path.push_back(temp->val);
            if (temp->left) my_queue.push(temp->left);
            if (temp->right) my_queue.push(temp->right);
        }
        result.push_back(path);
    }
    reverse(result.begin(),result.end());
    return result;
}

