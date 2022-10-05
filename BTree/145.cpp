/*
@File  :145.cpp
@Author:dfc
@Date  :2022/10/5  15:29
@Desc  :后续遍历
*/

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


vector<int> postorderTraversal(TreeNode* root);
void postorderTraversal_1(TreeNode* t,vector<int>& result);
int main()
{

}

/* 这是递归的写法
vector<int> postorderTraversal(TreeNode* root)
{
    vector<int> result;
    postorderTraversal_1(root,result);
    return result;
}

void postorderTraversal_1(TreeNode* t,vector<int>& result)
{
    if (t==NULL) return;
    postorderTraversal_1(t->left,result);
    postorderTraversal_1(t->right,result);
    result.push_back(t->val);

}
*/

vector<int> postorderTraversal(TreeNode* root)
{
    TreeNode *p;
    vector<int> result;
    stack<TreeNode*> s1;
    stack<int> s2;

    if (!root) return result;

    s1.push(root);
    s2.push(0);

    while (!s1.empty())
    {
        p = s1.top();
        int flag = s2.top();
        switch (flag) {
            case 0:
            {
                s2.top() = 1;
                if (p->left)
                {
                    s1.push(p->left);
                    s2.push(0);
                }
                break;
            }
            case 1:
            {
                s2.top() = 2;
                if (p->right)
                {
                    s1.push(p->right);
                    s2.push(0);
                }
                break;
            }
            case 2:
            {
                result.push_back(p->val);
                s1.pop();
                s2.pop();
                break;
            }
        }
    }
    return result;
}
