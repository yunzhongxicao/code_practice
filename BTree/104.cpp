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

/* ���ǵݹ��д�� �����õ��Ǻ������ ����������Ҫע�����
 * ����� Ӧ����ǰ�����
 * ��߶� Ӧ���Ǻ������
 * �����ú��������ԭ�� ����Ϊ�����Ⱦ��Ǹ��ڵ�ĸ߶�
int maxDepth(TreeNode* root)
{
    if (!root) return 0;
    int left_depth,right_depth;
    left_depth = maxDepth(root->left);
    right_depth = maxDepth(root->right);

    return 1 + max(left_depth,right_depth);
}*/

// ����������Ȼ��ݵ�ǰ�����
void get_depth(TreeNode* p, int depth, int &result);
int maxDepth(TreeNode* root)
{
    int result=0;
    if (!root) return 0;
    get_depth(root,1,result);
    return result;
}

void get_depth(TreeNode* p, int depth, int &result) // ��ÿ���ڵ� ��¼��ǰ�߶� �Լ�һ���ᴩ���������߶�
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
