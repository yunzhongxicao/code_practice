/*
@File  :144.cpp
@Author:dfc
@Date  :2022/10/5  14:54
@Desc  : 二叉树的前序遍历
*/
// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode() : val(0), left(nullptr), right(nullptr) {}
//      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//       TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  };

#include "iostream"
#include "vector"
#include "stack"

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
public:
    TreeNode(){val=0;left=NULL;right=NULL;};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};


vector<int> preorderTraversal(TreeNode* root);
void preorderTraversal_1(TreeNode* t,vector<int>& result);
int main()
{

}

/* 这是递归的写法
vector<int> preorderTraversal(TreeNode* root)
{
    vector<int> result;
    preorderTraversal_1(root,result);
    return result;
}

void preorderTraversal_1(TreeNode* t,vector<int>& result)
{
    if (t==NULL) return;
    result.push_back(t->val);
    preorderTraversal_1(t->left,result);
    preorderTraversal_1(t->right,result);
}*/

vector<int> preorderTraversal(TreeNode* root)
{
    stack<TreeNode*> s1;
    vector<int> result;
    TreeNode *p,*pl,*pr;
    if (!root)
        return result;
    s1.push(root);

    while (!s1.empty())
    {
        p = s1.top();
        result.push_back(p->val);
        s1.pop();
        if (p->right)
        {
            s1.push(p->right);
        }
        if(p->left)
        {
            s1.push(p->left);
        }
    }
    return result;
}
