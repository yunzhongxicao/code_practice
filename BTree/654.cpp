/*
@File  :654.cpp
@Author:dfc
@Date  :2022/10/14  10:16
@Desc  : ×î´ó¶þ²æÊ÷
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
TreeNode *root;
TreeNode* constructMaximumBinaryTree(vector<int>& nums);
TreeNode* traversal(vector<int> nums,int left,int right);

TreeNode* constructMaximumBinaryTree(vector<int>& nums)
{
    int left = 0,right =(int) nums.size()-1;
    traversal(nums,left,right);
    return root;
}

TreeNode* traversal(vector<int> nums,int left,int right)
{
    TreeNode *p;
    if (left>right) return NULL;

    int max_value=-1,max_index=0;
    for (int i = left; i <=right ; ++i) {
        if (nums[i]>max_value)
        {
            max_value = nums[i];
            max_index = i;
        }
    }

    p = new TreeNode(max_value);

    if (!root) root=p;

    // ×ó±ßÐòÁÐ
    int left_left = left,left_right = max_index-1;

    TreeNode *left_node = traversal(nums,left_left,left_right);

    //ÓÒ±ßÐòÁÐ
    int right_left= max_index+1, right_right = right;
    TreeNode *right_node = traversal(nums,right_left,right_right);


    p->left = left_node;
    p->right = right_node;

    return p;


}
