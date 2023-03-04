/*
@File  :199_second.cpp
@Author:dfc
@Date  :2023/3/2  10:43
@Desc  : ¶þ²æÊ÷µÄÓÒÊÓÍ¼
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
    queue<TreeNode *> my_queue;
    if (!root) return result;
    my_queue.push(root);
    while (!my_queue.empty())
    {
        int size = my_queue.size();
        vector<int>path;
        for (int i = 0; i < size; ++i) {
            TreeNode *temp = my_queue.front();
            my_queue.pop();
            path.push_back(temp->val);
            if (temp->left) my_queue.push(temp->left);
            if (temp->right) my_queue.push(temp->right);
        }
        result.push_back(path.back());
    }
    return result;
}

