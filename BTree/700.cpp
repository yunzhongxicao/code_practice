/*
@File  :700.cpp
@Author:dfc
@Date  :2022/10/14  11:46
@Desc  : �����������е�����
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

TreeNode* searchBST(TreeNode* root, int val);

/* �ݹ鷨
TreeNode* searchBST(TreeNode* root, int val)
{
    if (!root) return nullptr;
    if (root->val == val) return root;
    TreeNode *left;
    TreeNode *right;
    if (root->val >val)
    {
        left =  searchBST(root->left,val);
    }
    else if (root->val <val)
    {
        right=searchBST(root->right,val);
    }
    if (left== nullptr and right== nullptr)
        return nullptr;
    else if (left!= nullptr)
        return left;
    else if (right!= nullptr)
        return right;
}
*/
/*
TreeNode* searchBST(TreeNode* root, int val)
{
    if (!root) return nullptr;
    if (root->val == val) return root;
    TreeNode *result;  // ��Ϊ������������ʵ���з���� ������ ������ ֻ����һ�������Ҫô����Ҫô����
                        // ���Բ���Ҫ���������������������ؽڵ� ֻ��Ҫһ���������
    if (root->val >val)
    {
        result =  searchBST(root->left,val);
    }
    else if (root->val <val)
    {
        result=searchBST(root->right,val);
    }
    return result;  // �������ֵ�ǿ���һ������ϴ���ȥ��
}*/

TreeNode* searchBST(TreeNode* root, int val)
{
    TreeNode *p;
    if (!root) return nullptr;
    p = root;
    while (p!= nullptr)
    {
        if (p->val > val)
        {
            p= p->left;
        } else if (p->val < val)
        {
            p = p->right;
        } else
        {
            break;
        }
    }
    return p;
}
