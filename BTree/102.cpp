/*
@File  :102.cpp
@Author:dfc
@Date  :2022/10/5  16:45
@Desc  : 层序遍历
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

vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>> result;
    queue<TreeNode*> my_queue;
    TreeNode *p;

    if (!root) return result;

    my_queue.push(root);

    while (!my_queue.empty())
    {
        vector<int> val;
        int size = my_queue.size();

        for (int i = 0; i < size; ++i) {   // 通过添加一个for循环 一次把一层的弹出来
            p = my_queue.front();
            val.push_back(p->val);
            my_queue.pop();
            if (p->left) my_queue.push(p->left);
            if (p->right) my_queue.push(p->right);
        }
        result.push_back(val);

    }
    return result;
}


