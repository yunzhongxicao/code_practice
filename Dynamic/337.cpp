/*
@File  :337.cpp
@Author:dfc
@Date  :2022/11/15  12:32
@Desc  : 打家劫舍3
*/
#include "vector"
#include "iostream"
using namespace std;


struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<int>  rob_traversal(TreeNode *p);
int rob(TreeNode* root)
{
    if (!root) return 0;
    vector<int> result = rob_traversal(root);
    return max(result[0],result[1]);
}

vector<int>  rob_traversal(TreeNode *p)
{
    // 下标0 不偷  下标1 偷
    if (!p) return vector<int>{0,0};
    vector<int> left_value = rob_traversal(p->left);
    vector<int> right_value = rob_traversal(p->right);
    int tmp0 = max(left_value[0],left_value[1])+max(right_value[0],right_value[1]);
    int tmp1 = p->val+left_value[0]+right_value[0];
    return vector<int>{tmp0,tmp1};
}