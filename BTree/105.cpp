/*
@File  :105.cpp
@Author:dfc
@Date  :2022/10/13  21:57
@Desc  :
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
TreeNode *bulid_tree(vector<int> pre, int pl, int pr, vector<int> mid, int ml,int mr);

TreeNode *bulid_tree(vector<int> pre, int pl, int pr, vector<int> mid, int ml,int mr)
{
    TreeNode *p,*left_root,*right_root;
    int lpl,lpr,lml,lmr;
    int rpl,rpr,rml,rmr;

    if (pl>pr) return NULL; // 相等的时候不能跳出来 因为要把这个null给连进去

    p = new TreeNode (pre[pl]);
    if (!root) root = p;

    int i;
    for (i = ml; i <=mr ; ++i) {
        if (mid[i] == pre[pl])
        {
            break;
        }
    }
    int pos = i;
    int num = pos - ml;
    // 找左子树
    lpl = pl+1; lpr = pl+num;
    lml = ml;  lmr = pos-1;

    left_root = bulid_tree(pre,lpl,lpr,mid,lml,lmr);


    // 找右子树
    rpl = pl+num +1; rpr = pr;
    rml = pos+1; rmr = mr;
    right_root = bulid_tree(pre,rpl,rpr,mid,rml,rmr);

    p->left = left_root;
    p->right = right_root;

    return p;

}



TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    int ml=0,mr = (int)inorder.size()-1;
    int pl= 0,pr = (int)preorder.size()-1;

    bulid_tree(preorder,pl,pr,inorder,ml,mr);
    return root;
}