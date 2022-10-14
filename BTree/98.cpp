/*
@File  :98.cpp
@Author:dfc
@Date  :2022/10/14  12:23
@Desc  :ÑéÖ¤¶þ²æËÑË÷Ê÷
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


bool isValidBST(TreeNode* root)
{

    if (root->left==NULL and root->right==NULL) return true;

    bool root_flag;
    if (root->left==NULL and root->right->val > root->val) root_flag= true;
    else if (root->right==NULL and root->left->val < root->val) root_flag= true;
    else if (root->val > root->left->val and root->val < root->right->val)
        root_flag = true;
    else root_flag = false;

    bool left_flag = isValidBST(root->left);
    bool right_flag = isValidBST(root->right);

    return root_flag&&left_flag&&right_flag;
}
