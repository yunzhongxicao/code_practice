/*
@File  :530.cpp
@Author:dfc
@Date  :2022/10/14  21:42
@Desc  : 二叉搜索树的最小绝对差
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


/* 递归写法
TreeNode *last_node= nullptr;
int min_value=INT32_MAX;
void traverse(TreeNode *p);
int getMinimumDifference(TreeNode* root)
{
    if (!root) return 0;

    traverse(root);
    return min_value;

}

void traverse(TreeNode *p)
{
    if (!p) return;
    traverse(p->left);
    if (last_node)
    {
        int tmp = abs(p->val - last_node->val);
        min_value = tmp<= min_value?tmp:min_value;
    }
    last_node=p;

    traverse(p->right);

}*/

int getMinimumDifference(TreeNode* root)
{
    stack<TreeNode*> s1;
    stack<int> s2;
    TreeNode *p;
    TreeNode *last_node= nullptr;
    int result=INT32_MAX;
    if (!root) return 0;

    s1.push(root);
    s2.push(0);

    while (!s1.empty())
    {
        p = s1.top();
        int flag = s2.top();

        if (flag==0)
        {
            s2.top()=1;
            if (p->left)
            {
                s1.push(p->left);
                s2.push(0);
            }
        }
        else if (flag==1)
        {
            s1.pop();
            s2.pop();
            if (last_node!= nullptr)
            {
                int tmp = abs(p->val - last_node->val);
                result = tmp<=result?tmp:result;
            }
            last_node=p;

            if (p->right)
            {
                s1.push(p->right);
                s2.push(0);
            }
        }
    }
    return result;

}
