/*
@File  :offer_26.cpp
@Author:dfc
@Date  :2022/12/22  21:01
@Desc  : �����ӽṹ
*/
#include "iostream"
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
bool dp(TreeNode* t1, TreeNode* t2);

bool isSubStructure(TreeNode* A, TreeNode* B)
{
    if (A== nullptr or B == nullptr) return false;
    if (A->val and B->val and dp(A,B)) return true;
    return isSubStructure(A->left,B) or isSubStructure(A->right,B);
}

bool dp(TreeNode* t1, TreeNode* t2)// ��������Ĺ������ж� ��AΪͷ�ڵ�Ķ������Ƿ� ����B�������A��ʼ
{
    if (t2== nullptr) return true;
    if (t1== nullptr) return false;
    bool left,right;
    if (t1->val != t2->val)
    {
        return false;  // �������� ֱ�Ӿ��жϲ�����
    }
    else
    {
        left = dp(t1->left,t2->left);
        right = dp(t1->right,t2->right);
    }
    return left and right;  // ��Ҫa b ��� ҲҪ�����������

}

