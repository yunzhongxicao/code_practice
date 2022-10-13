/*
@File  :104.cpp
@Author:dfc
@Date  :2022/10/5  20:42
@Desc  : 最大深度
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
/* 这是迭代的写法 运用层序遍历
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

        for (int i = 0; i < size; ++i) {   // 通过添加一个for循环 一次把一层的弹出来
            p = my_queue.front();
            my_queue.pop();
            if (p->left) my_queue.push(p->left);
            if (p->right) my_queue.push(p->right);
        }
        depth++;
    }
    return depth;
}*/

/* 这是递归的写法 但是用的是后序遍历 但是这里需要注意的是
 * 求深度 应该是前序遍历
 * 求高度 应该是后序遍历
 * 这里用后序遍历的原因 是因为最大深度就是根节点的高度
int maxDepth(TreeNode* root)
{
    if (!root) return 0;
    int left_depth,right_depth;
    left_depth = maxDepth(root->left);
    right_depth = maxDepth(root->right);

    return 1 + max(left_depth,right_depth);
}*/

// 真正体现深度回溯的前序遍历
void get_depth(TreeNode* p, int depth, int &result);
int maxDepth(TreeNode* root)
{
    int result=0;
    if (!root) return 0;
    get_depth(root,1,result);
    return result;
}

void get_depth(TreeNode* p, int depth, int &result) // 在每个节点 记录当前高度 以及一个贯穿的整体最大高度
{
    result = depth>result?depth:result;

    if (p->left==NULL and p->right==NULL)
        return;
    if (p->left)
    {
        depth++;
        get_depth(p->left,depth,result);
        depth--;
    }
    if (p->right)
    {
        depth++;
        get_depth(p->right,depth,result);
        depth--;
    }
    return;
}
