/*
@File  :offer_55_1.cpp
@Author:dfc
@Date  :2023/1/13  14:23
@Desc  : �������ĸ߶�
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
int max_value = 0;
int result = 0;
void backtracking(TreeNode *p);
int maxDepth(TreeNode* root)
{
    if (!root) return 0;
    max_value = 1;
    backtracking(root);
    return result;
}

void backtracking(TreeNode *p) // �ڽ�����һ��ǰ�Ѿ��Ѹ߶�+1
{
    result = max(result,max_value); // ����֮��������¼��ǰ�ڵ�ĸ߶�
    if (p->left == nullptr and p->right== nullptr)
        return;
    if (p->left) {
        max_value++;
        backtracking(p->left);
        max_value--;
    }
    if (p->right) {
        max_value++;
        backtracking(p->right);
        max_value--;
    }
}

