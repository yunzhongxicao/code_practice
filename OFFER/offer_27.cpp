/*
@File  :offer_27.cpp
@Author:dfc
@Date  :2022/12/22  23:42
@Desc  :¶þ²æÊ÷µÄ¾µÏñ
*/
#include "iostream"
#include "queue"
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* mirrorTree(TreeNode* root)
{
    if (!root) return root;
    queue<TreeNode*>my_queue;
    my_queue.push(root);
    TreeNode *p;
    while (!my_queue.empty())
    {
        int size = my_queue.size();
        for (int i = 0; i < size; ++i) {
            p = my_queue.front();
            swap(p->left,p->right);
            my_queue.pop();
            if (p->left) my_queue.push(p->left);
            if (p->right) my_queue.push(p->right);
        }
    }
    return root;
}

