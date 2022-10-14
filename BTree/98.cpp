/*
@File  :98.cpp
@Author:dfc
@Date  :2022/10/14  12:23
@Desc  :��֤����������
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


/* ����д��
bool isValidBST(TreeNode* root)
{

    if (root->left==NULL and root->right==NULL) return true;

    bool root_flag;
    if (root->left==NULL and root->right->val > root->val) root_flag= true;
    else if (root->right==NULL and root->left->val < root->val) root_flag= true;
    else if (root->val > root->left->val and root->val < root->right->val)  // ����д���Ǵ�� ����ÿ���ڵ��໥�Ƚ� ��Ҫ��ڵ㶼����С �ҽڵ㶼������
        root_flag = true;
    else root_flag = false;

    bool left_flag = isValidBST(root->left);
    bool right_flag = isValidBST(root->right);

    return root_flag&&left_flag&&right_flag;
}
*/
/* �ݹ��д��
 * TreeNode *pre=NULL;
bool isValidBST(TreeNode* root) //
{
    if (!root) return true;

    bool left = isValidBST(root->left);

    if (pre !=NULL and root->val <= pre->val) return false;
    else pre = root;


    bool right = isValidBST(root->right);

    return left&&right;


}*/

// ������д��
bool isValidBST(TreeNode* root) //
{
    stack<TreeNode*> s1;
    stack<int> s2;

    TreeNode *p;
    int flag;

    TreeNode *last_node= nullptr;

    if (!root) return true;

    s1.push(root);
    s2.push(0)  ;

    while (!s1.empty())
    {
        p = s1.top();
        flag = s2.top();
        if (flag==0)
        {
            s2.top()=1;
            if (p->left)
            {
                s1.push(p->left);
                s2.push(0);
            }
        }
        else if (flag==1)
        {
            s1.pop();
            s2.pop();
            if (last_node != nullptr and last_node->val >= p->val) return false; // last_node != nullptr  ֻ���ʼ��ʱ�����Ч ����ʱ�򲻿����ǿ�ָ��
            else last_node = p;
            if (p->right)
            {
                s1.push(p->right);
                s2.push(0);
            }
        }
    }
    return true;

}
