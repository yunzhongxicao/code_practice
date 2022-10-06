/*
@File  :104.cpp
@Author:dfc
@Date  :2022/10/5  20:42
@Desc  : ������
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
/* ���ǵ�����д�� ���ò������
int maxDepth(TreeNode* root)
{
    queue<TreeNode*> my_queue;
    TreeNode *p;
    int depth = 0;

    if (!root) return 0;

    my_queue.push(root);

    while (!my_queue.empty())
    {
        int size = my_queue.size();

        for (int i = 0; i < size; ++i) {   // ͨ�����һ��forѭ�� һ�ΰ�һ��ĵ�����
            p = my_queue.front();
            my_queue.pop();
            if (p->left) my_queue.push(p->left);
            if (p->right) my_queue.push(p->right);
        }
        depth++;
    }
    return depth;
}*/


int maxDepth(TreeNode* root)
{
    if (!root) return 0;
    int left_depth,right_depth;
    left_depth = maxDepth(root->left);
    right_depth = maxDepth(root->right);

    return 1 + max(left_depth,right_depth);
}

