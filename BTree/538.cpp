/*
@File  :538.cpp
@Author:dfc
@Date  :2022/10/18  19:58
@Desc  : 二叉累加树
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

/* 递归的写法
int sum=0;
void traversal(TreeNode *p);
TreeNode* convertBST(TreeNode* root)
{
    traversal(root);
    return root;
}

void traversal(TreeNode *p)
{
    if (p== nullptr) return;
    traversal(p->right);
    sum+=p->val;
    p->val=sum;
    traversal(p->left);
}*/

//迭代的写法
TreeNode* convertBST(TreeNode* root)
{
    stack<TreeNode *> s1;
    stack<int> s2;

    TreeNode *p;
    int flag;
    int sum=0;

    if (!root) return root;
    s1.push(root);
    s2.push(0);

    while (!s1.empty())
    {
        p = s1.top();
        flag = s2.top();
        if (flag==0)
        {
            s2.top()=1;
            if (p->right)
            {
                s1.push(p->right);
                s2.push(0);
            }
        }
        else if (flag==1)
        {
            s1.pop();
            s2.pop();

            sum +=p->val;
            p->val = sum;


            if (p->left)
            {
                s1.push(p->left);
                s2.push(0);
            }
        }
    }
    return root;
}