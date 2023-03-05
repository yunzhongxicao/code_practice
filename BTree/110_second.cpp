/*
@File  :110_second.cpp
@Author:dfc
@Date  :2023/3/5  16:04
@Desc  : Æ½ºâ¶þ²æÊ÷
*/
#include "iostream"
#include "vector"

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){};
};

int get_height(TreeNode *p)
{
    if (!p) return 0;
    int left_height = get_height(p->left);
    int right_height = get_height(p->right);
    if (left_height==-1 or right_height==-1)
        return -1;
    if (abs(left_height-right_height)>1)
        return -1;
    return 1+ max(left_height,right_height);
}

bool isBalanced(TreeNode* root)
{
    return get_height(root)!=-1;

}



