/*
@File  :offer_2_046.cpp
@Author:dfc
@Date  :2023/5/11  8:31
@Desc  :
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

vector<int> rightSideView(TreeNode* root)
{
    vector<int> result;
    if (!root) return result;
    queue<TreeNode *> my_queue;
    my_queue.push(root);
    while (!my_queue.empty())
    {
        int size = my_queue.size();
        int max_value;
        for (int i = 0; i < size; ++i) {
            TreeNode *temp = my_queue.front();
            my_queue.pop();
            max_value = temp->val;
            if (temp->left) my_queue.push(temp->left);
            if (temp->right) my_queue.push(temp->right);
        }
        result.push_back(max_value);
    }
    return result;
}

