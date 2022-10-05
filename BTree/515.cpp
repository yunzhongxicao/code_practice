/*
@File  :515.cpp
@Author:dfc
@Date  :2022/10/5  19:33
@Desc  : 树行中找最大值
*/

#include "iostream"
#include "stack"
#include "vector"
#include "queue"
#include "algorithm"

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
public:
    TreeNode(){val=0;left=NULL;right=NULL;};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

vector<int> largestValues(TreeNode* root)
{
    vector<int> result;
    queue<TreeNode*> my_queue;
    TreeNode *p;

    if (!root) return result;

    my_queue.push(root);

    while (!my_queue.empty())
    {
        int size = my_queue.size();
        int max = INT32_MIN;

        for (int i = 0; i < size; ++i) {   // 通过添加一个for循环 一次把一层的弹出来
            p = my_queue.front();
            my_queue.pop();
            if (p->val > max) max = p->val;
            if (p->left) my_queue.push(p->left);
            if (p->right) my_queue.push(p->right);
        }
        result.push_back(max);

    }
    return result;
}
