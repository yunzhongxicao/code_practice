/*
@File  :offer_34.cpp
@Author:dfc
@Date  :2022/12/25  16:03
@Desc  : �������к�Ϊĳһֵ��·��
*/
#include "vector"
#include "iostream"
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void backtracking(TreeNode *p, int target);
vector<int>path;
vector<vector<int>>result;
int sum;
vector<vector<int>> pathSum(TreeNode* root, int target)
{
    if(!root) return result;
    sum = root->val;
    path.push_back(sum);
    backtracking(root,target);
    return result;
}

void backtracking(TreeNode *p, int target) // sum��¼�Ľ���p��һ��Ľڵ��ĺ�
{
    if (p->left== nullptr and p->right== nullptr) // ע�� ��ʱҶ�ӽڵ�û���ں�����м�����  ����Ҫ����һ������
    {
        if (sum==target) result.push_back(path);
        return;
    }
    if (p->left)
    {
        sum += p->left->val;
        path.push_back(p->left->val);
        backtracking(p->left, target);
        sum -= p->left->val;
        path.pop_back();
    }
    if (p->right)
    {
        sum += p->right->val;
        path.push_back(p->right->val);
        backtracking(p->right,target);
        sum -= p->right->val;
        path.pop_back();
    }
}