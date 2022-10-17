/*
@File  :235.cpp
@Author:dfc
@Date  :2022/10/17  9:58
@Desc  : 二叉搜索树的最近公共祖先
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
/*
void traversal(TreeNode *t,int min_value, int max_value);
TreeNode *result;
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (!root) return root;
    int min_value = min(p->val,q->val);
    int max_value = max(p->val,q->val);
    traversal(root,min_value,max_value);
    return result;

}


void traversal(TreeNode *t,int min_value, int max_value)
{
    if (!t) return;
    if (t->val >=min_value and t->val<= max_value)
    {
        result = t;
        return;
    }
    if (t->val > max_value)
        traversal(t->left,min_value,max_value);
    else if (t->val < min_value)
        traversal(t->right,min_value,max_value);
}*/

// 迭代的解法 其实就是搜索节点
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    int min_value = min(p->val,q->val);
    int max_value = max(p->val,q->val);
    while (root) {
        if (root->val >= min_value and root->val <= max_value) {
            return root;
        }
        if (root->val > max_value)
            root = root->left;
        else if (root->val < min_value)
            root = root->right;
    }
    return root;
}