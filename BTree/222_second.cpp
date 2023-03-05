/*
@File  :222_second.cpp
@Author:dfc
@Date  :2023/3/5  15:52
@Desc  : ��ȫ�������Ľڵ����
*/
#include "iostream"
#include "queue"
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){};
};


/*int countNodes(TreeNode* root) // ��������ķ���
{
    queue<TreeNode *> my_queue;
    int result=0;
    if (!root) return result;
    my_queue.push(root);
    while (!my_queue.empty())
    {
        TreeNode *p = my_queue.front();
        my_queue.pop();
        if (p->left) my_queue.push(p->left);
        if (p->right) my_queue.push(p->right);
        result++;
    }
    return result;
}*/

int countNodes(TreeNode* root) // �ݹ�ķ���
{
    if (!root) return 0;
    return 1+countNodes(root->left) + countNodes(root->right);
}




