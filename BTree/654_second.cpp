/*
@File  :654_second.cpp
@Author:dfc
@Date  :2023/3/8  20:08
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

TreeNode *build_tree(vector<int> &nums, int start, int end)
{
    if (start>end)
        return nullptr;
    int l_start,l_end;
    int r_start, r_end;
    int pos;
    int max_value=-1;
    for (int i = start; i <=end ; ++i) {
        if (nums[i]>max_value)
        {
            pos = i;
            max_value = nums[i];
        }
    }
    TreeNode *p = new TreeNode(max_value);
    l_start = start; l_end = pos-1;
    r_start=pos+1; r_end = end;
    TreeNode *left_node = build_tree(nums,l_start,l_end);
    TreeNode *right_node = build_tree(nums,r_start,r_end);
    p->left = left_node;
    p->right = right_node;
    return p;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums)
{
    TreeNode *root  = build_tree(nums,0,nums.size()-1);
    return root;
}

