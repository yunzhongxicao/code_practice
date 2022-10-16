/*
@File  :236.cpp
@Author:dfc
@Date  :2022/10/16  21:02
@Desc  : �������������������
*/

#include "iostream"
#include "stack"
#include "vector"
#include "queue"
#include "algorithm"
#include "map"
#include "unordered_map"

using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
public:
    TreeNode(){val=0;left=NULL;right=NULL;};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (root== nullptr or root==p or root==q) return root; // �������ֹ����������ҵ��˽ڵ㣬������ֹ�ݹ飬���ڵ㷵�س�ȥ

    TreeNode *left_node = lowestCommonAncestor(root->left,p,q);

    TreeNode *right_node = lowestCommonAncestor(root->right,p,q);

    if (left_node== nullptr and right_node== nullptr) return nullptr;

    if (left_node != nullptr and right_node != nullptr) return root;

    return left_node== nullptr?right_node: left_node;

}