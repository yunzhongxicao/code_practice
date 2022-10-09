/*
@File  :222.cpp
@Author:dfc
@Date  :2022/10/9  10:56
@Desc  : ��ȫ�������Ľڵ����
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
/*
int countNodes(TreeNode* root) // ���õݹ�ķ�����
{
    int count;
    if (!root)  return 0;
    int left_count = countNodes(root->left);
    int right_count = countNodes(root->right);
    return 1+left_count+right_count;
}*/


int countNodes(TreeNode* root)  // �ò�������ķ���
{
    int count=0;
    queue<TreeNode*> my_queue;
    TreeNode *p;

    if (!root) return 0;

    my_queue.push(root);
    while (!my_queue.empty())
    {
        p = my_queue.front();
        count++;
        my_queue.pop();
        if (p->left) my_queue.push(p->left);
        if (p->right) my_queue.push(p->right);
    }
    return count;
}
