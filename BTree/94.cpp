/*
@File  :94.cpp
@Author:dfc
@Date  :2022/10/5  16:03
@Desc  :ÖÐÐò±éÀú
*/

#include "iostream"
#include "stack"
#include "vector"

using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
public:
    TreeNode(){val=0;left=NULL;right=NULL;};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

vector<int> inorderTraversal(TreeNode* root)
{
    stack<TreeNode*> s1;
    stack<int> s2;
    TreeNode *p;
    vector<int> result;
    if(!root) return result;

    s1.push(root);
    s2.push(0);

    while (!s1.empty())
    {
        p = s1.top();
        int  flag = s2.top();
        if (flag == 0)
        {
            s2.top() = 1;
            if (p->left)
            {
                s1.push(p->left);
                s2.push(0);
            }
        } else if (flag==1)
        {
            result.push_back(p->val);
            s1.pop();
            s2.pop();
            if (p->right)
            {
                s1.push(p->right);
                s2.push(0);
            }
        }
    }
    return result;
}
