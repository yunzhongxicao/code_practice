/*
@File  :106_second.cpp
@Author:dfc
@Date  :2023/3/7  10:56
@Desc  :
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

TreeNode * build(vector<int> & inorder, vector<int>& postorder, int ml, int mr, int pl, int pr)
{
    int lml, lmr, lpl, lpr;
    int rml, rmr, rpl, rpr;
    if (ml>mr)
        return nullptr;
    int pos;
    TreeNode *p = new TreeNode(postorder[pr])  ;
    for (int i = ml; i <=mr ; ++i) {
        if (inorder[i] == p->val)
        {
            pos = i;
            break;
        }
    }
    lml = ml; lmr = pos-1;  lpl=pl; lpr = lpl + (lmr-lml);
    rml = pos+1; rmr = mr; rpl=lpr+1; rpr = pr-1;
    TreeNode *  left_node = build(inorder,postorder, lml,lmr,lpl,lpr);
    TreeNode * right_node = build(inorder,postorder,rml,rmr,rpl,rpr);
    p->left = left_node;
    p->right = right_node;
    return p;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
    TreeNode * root = build(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    return root;
}


