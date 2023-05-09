/*
@File  :offer_2_043.cpp
@Author:dfc
@Date  :2023/5/9  11:28
@Desc  : 往完全二叉树添加节点
*/
#include "iostream"
#include "vector"
#include "queue"
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class CBTInserter {
public:
    vector<TreeNode*> node_vec;
    CBTInserter(TreeNode* root) {
        node_vec.push_back(nullptr);
        queue<TreeNode *> my_queue;
        my_queue.push(root);
        node_vec.push_back(root);
        while (!my_queue.empty())
        {
            TreeNode * temp = my_queue.front();
            my_queue.pop();
            node_vec.push_back(temp);
            if (temp->left) my_queue.push(temp->left);
            if (temp->right) my_queue.push(temp->right);
        }
    }

    int insert(int v) {
        TreeNode *child = new TreeNode(v);
        node_vec.push_back(child);
        TreeNode * parent = node_vec[(node_vec.size()-1)/2];
        if ((node_vec.size()-1) % 2==0) parent->left = child;
        else parent->right = child;
        return parent->val;
    }

    TreeNode* get_root() {
        return node_vec[1];
    }
};
