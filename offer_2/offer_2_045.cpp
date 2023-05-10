/*
@File  :offer_2_045.cpp
@Author:dfc
@Date  :2023/5/10  9:05
@Desc  :
*/
#include "bits/stdc++.h"
using namespace std;

struct  TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){};
};

int findBottomLeftValue(TreeNode* root) {
    int result;
    if (!root) return result;
    queue<TreeNode *> my_queue;
    my_queue.push(root);
    while (!my_queue.empty())
    {
        int size = my_queue.size();
        for (int i = 0; i < size; ++i) {
            TreeNode *temp = my_queue.front();
            my_queue.pop();
            if (i==0)
                result = temp->val;
            if (temp->left) my_queue.push(temp->left);
            if (temp->right) my_queue.push(temp->right);
        }
    }
    return result;
}

