/*
@File  :617.cpp
@Author:dfc
@Date  :2022/10/14  10:39
@Desc  : 合并二叉树
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
TreeNode *root;
TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2);
/* 这是递归的写法
TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
{
    if (!root1 and  !root2) return NULL;

    TreeNode *p;

    if (root1==NULL and root2 != NULL)
    {
        p = root2;
        if (!root) root = p;
        return p;
    }
    else if (root1!=NULL and root2 == NULL )
    {
        p =root1;
        if (!root) root = p;
        return p;
    } else
    {
        p = new TreeNode(root1->val + root2->val);
        if (!root) root = p;
        TreeNode *left_node = mergeTrees(root1->left,root2->left);
        TreeNode *right_node = mergeTrees(root1->right,root2->right);

        p->left = left_node;
        p->right = right_node;
        return p;
    }

}*/

// 迭代 的写法
TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
{
    queue<TreeNode*> my_queen;
    if (!root1) return root2;
    if (!root2) return root1;
    my_queen.push(root1);
    my_queen.push(root2);

    while (!my_queen.empty())
    {
        TreeNode *p1 = my_queen.front(); my_queen.pop();
        TreeNode *p2 = my_queen.front(); my_queen.pop();

        p1->val = p1->val + p2->val;

        if (p1->left!=NULL and p2->left !=NULL)
        {
            my_queen.push(p1->left);
            my_queen.push(p2->left);
        }

        if (p1->right !=NULL and p2->right !=NULL)
        {
            my_queen.push(p1->right);
            my_queen.push(p2->right);
        }

        if (p1->left ==NULL and p2->left !=NULL) // 如果是p2左子不为空 直接把p1给接过去就行
                                                // 如果p1 左子不为空 p2 左子为空 不用管
        {
            p1->left = p2->left;
        }
        if (p1->right ==NULL and p2->right!=NULL)
        {
            p1->right = p2->right;
        }
    }
    return root1;
}