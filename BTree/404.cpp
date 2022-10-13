/*
@File  :404.cpp
@Author:dfc
@Date  :2022/10/9  17:14
@Desc  : ��Ҷ��֮��
*/

#include "iostream"
#include "stack"
#include "vector"
#include "queue"
#include <numeric>

using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
public:
    TreeNode(){val=0;left=NULL;right=NULL;};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};
int sumOfLeftLeaves(TreeNode* root);
void find_left(TreeNode *t,vector<int> &left_vector);


/* �ݹ��д�� �Ҿ��ñȴ�������¼������
void find_left(TreeNode *t,vector<int> &left_vector)
{

    if (t->left!=NULL and t->left->left==NULL and t->left->right==NULL)  // ����ҵ�����Ҷ�� ��push��ȥ
    {
        left_vector.push_back(t->left->val);
    }

    if (t->left==NULL and t->right==NULL)  // �жϵ�Ҷ�ӽڵ�Ϊֹ  Ȼ�������������֤��t����Ϊ��
    {
        return;
    }
    if (t->left)
    {
        find_left(t->left,left_vector);
    }
    if (t->right)
    {
        find_left(t->right,left_vector);
    }
}

int sumOfLeftLeaves(TreeNode* root)
{
    if (!root) return 0;
    vector<int> result;
    find_left(root,result);

    return accumulate(result.begin(),result.end(),0);
}*/

int sumOfLeftLeaves(TreeNode* root)
{
    stack<TreeNode*> s1;

    TreeNode *p;
    int result=0;

    if (!root) return 0;

    s1.push(root);
    while (!s1.empty())
    {
        p = s1.top();
        s1.pop();

        if (p->left!=NULL and p->left->left==NULL and p->left->right==NULL)
        result+=p->left->val;

        if (p->left) s1.push(p->left);
        if (p->right) s1.push(p->right);

    }
    return result;
}

