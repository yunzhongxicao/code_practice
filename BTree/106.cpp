/*
@File  :106.cpp
@Author:dfc
@Date  :2022/10/13  11:58
@Desc  :�����������������й��������
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


TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);
TreeNode* build_tree(vector<int> &inorder,int ml,int mr,vector<int>&postorder,int pl,int pr);
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
    int ml=0,mr = (int)inorder.size()-1;
    int pl= 0,pr = (int)postorder.size()-1;

    build_tree(inorder,ml,mr,postorder,pl,pr);
    return root;
}
TreeNode* build_tree(vector<int> &inorder,int ml,int mr,vector<int>&postorder,int pl,int pr)
// ÿ�δ���һ����Ӧ�ĺ�������򣬷�����ȷ���ĸ��ڵ�
// inorder �� postorder ÿ�β��� �������ʼ��������������֤ÿ�ζ��ǲ�ͬ���ִ���ȥ
{
    TreeNode *p;
    int lml,lmr,lpl,lpr;
    int rml,rmr,rpl,rpr;

    if (pl>pr) return NULL;

    p = new TreeNode(postorder[pr]);

    if (!root) root=p;

    int position; // �����и��ڵ��λ��

    for (int i = ml; i <= mr ; ++i) {
        if (inorder[i] == p->val)
        {
            position = i;
            break;
        }
    }

    int count = position-ml;

    // ������
    lml = ml; lmr = position-1;
    lpl = pl;lpr = pl+count-1;

    TreeNode *left_node = build_tree(inorder,lml,lmr,postorder,lpl,lpr);

    // ������
    rml = position+1;rmr = mr;
    rpl = lpr+1; rpr = pr-1;

    TreeNode *right_node = build_tree(inorder,rml,rmr,postorder,rpl,rpr);

    p->left = left_node;
    p->right=right_node;
    return p;

}