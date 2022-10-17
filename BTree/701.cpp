/*
@File  :701.cpp
@Author:dfc
@Date  :2022/10/17  11:13
@Desc  : 二叉搜索树中的插入操作
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

/*
TreeNode* insertIntoBST(TreeNode* root, int val)
{
    TreeNode *left_node= nullptr,*right_node= nullptr;
    if (root== nullptr)
    {
        auto *p = new TreeNode(val);
        return p;
    }
    else if (root->val > val)
        left_node= insertIntoBST(root->left,val);
    else if (root->val < val)
        right_node = insertIntoBST(root->right,val);

    if (left_node) root->left = left_node;
    if (right_node) root->right = right_node;
    return root;
}*/

// 迭代的写法
TreeNode* insertIntoBST(TreeNode* root, int val)
{
    TreeNode *last_node;
    TreeNode *cur = root;
    int flag=0;
    while (true)
    {
        if (cur== nullptr)
        {
            TreeNode *p = new TreeNode(val);
            if (flag==0 )root = p;  // 考虑的是一来就是空指针的情况
            if (flag==1) last_node->left = p;
            else if (flag==2) last_node->right = p;
            break;
        }
        else if (cur->val > val)
        {
            last_node= cur;
            cur = cur->left;
            flag = 1;
        }
        else if (cur->val < val)
        {
            last_node= cur;
            cur = cur->right;
            flag =2;
        }

    }
    return root;
}
