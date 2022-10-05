/*
@File  :111.cpp
@Author:dfc
@Date  :2022/10/5  20:49
@Desc  : 最小深度
*/

#include "iostream"
#include "stack"
#include "vector"
#include "queue"

using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
public:
    TreeNode(){val=0;left=NULL;right=NULL;};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

int minDepth(TreeNode* root)
{
    queue<TreeNode*> my_queue;
    TreeNode *p;
    int depth = 0;

    if (!root) return 0;

    my_queue.push(root);

    while (!my_queue.empty())
    {
        int size = my_queue.size();
        depth++;

        for (int i = 0; i < size; ++i) {   // 通过添加一个for循环 一次把一层的弹出来
            p = my_queue.front();
            my_queue.pop();
            if (p->left) my_queue.push(p->left);
            if (p->right) my_queue.push(p->right);
            if (!p->left and !p->right)
            {
                return depth;
            }
        }
    }
    return depth;
}