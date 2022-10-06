/*
@File  :100.cpp
@Author:dfc
@Date  :2022/10/6  19:32
@Desc  : ÏàÍ¬µÄÊ÷
*/
#include "iostream"
#include "stack"
#include "vector"
#include "queue"

using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
public:
    TreeNode(){val=0;left=NULL;right=NULL;};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

bool isSameTree(TreeNode* p, TreeNode* q)
{
    if (p == NULL and q==NULL) return true;
    else if (p==NULL and q!=NULL) return false;
    else if (p!=NULL and q== NULL) return false;
    else if (p->val != q->val) return false;

    bool left_flag,right_flag;
    left_flag = isSameTree(p->left,q->left);
    right_flag = isSameTree(p->right,q->right);

    return left_flag&&right_flag;
}


