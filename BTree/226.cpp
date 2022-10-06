/*
@File  :226.cpp
@Author:dfc
@Date  :2022/10/5  21:03
@Desc  : 翻转二叉树
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
void invertTree_1(TreeNode* t);


/*这是递归的写法
 * TreeNode* invertTree(TreeNode* root)
{
    invertTree_1(root);
    return root;
}

void invertTree_1(TreeNode* t)
{
    if (t==NULL) return;
    swap(t->left,t->right);
    invertTree_1(t->left);
    invertTree_1(t->right);

}*/

/*
TreeNode* invertTree(TreeNode* root) // 前序遍历
{
    stack<TreeNode*> s1;

    TreeNode *p;

    if (!root) return root;

    s1.push(root);

    while (!s1.empty())
    {
        p = s1.top();
        swap(p->left,p->right);
        s1.pop();
        if (p->left) s1.push(p->left);
        if (p->right) s1.push(p->right);
    }
    return root;

}
*/

TreeNode* invertTree(TreeNode* root) // 层序遍历
{
    queue<TreeNode*> my_queue;
    TreeNode *p;
    if (!root) return root;

    my_queue.push(root);

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


