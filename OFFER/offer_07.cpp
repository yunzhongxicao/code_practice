/*
@File  :offer_07.cpp
@Author:dfc
@Date  :2022/12/5  10:46
@Desc  : ����ǰ��� ���� �ؽ�������
*/
#include "iostream"
#include "vector"
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il,int ir);

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    TreeNode *root;
    root = build(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    return root;
}

TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il,int ir)
{
    int lpl,lpr, lil,lir; // ��ߵ�ǰ�������
    int rpl,rpr,ril,rir;  // �ұߵ�ǰ�������
    if (pl>pr) return NULL;
    TreeNode *p = new TreeNode(preorder[pl]);

    int pos;
    for (int i = il; i <=ir ; ++i) {
        if (inorder[i] == p->val)
        {
            pos= i;
            break;
        }
    }
    lpl =pl+1; lpr = pl + pos - il; lil = il; lir = pos-1;
    TreeNode * left = build(preorder,inorder,lpl,lpr,lil,lir);

    rpl = lpr+1; rpr = pr; ril = pos+1; rir = ir;
    TreeNode *right = build(preorder,inorder,rpl,rpr,ril,rir);
    p->left = left;
    p->right = right;
    return p;
}
