/*
@File  :108.cpp
@Author:dfc
@Date  :2022/10/18  12:04
@Desc  :有序数组转化为二叉搜索树
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

TreeNode *root= nullptr;
TreeNode* traversal(vector<int> nums,int left_index,int  right_index);
TreeNode* sortedArrayToBST(vector<int>& nums)
{
    int left_index = 0,right_index = (int) nums.size()-1;
    traversal(nums,left_index,right_index);
    return root;
}

TreeNode* traversal(vector<int> nums,int left_index,int  right_index) // 每次一个序列进去 要生成一个中间节点
{
    int size = right_index-left_index+1;
    int middle_index;
    if (size%2 ==0)
        middle_index=left_index+size/2-1;
    else middle_index = left_index + (int)size/2;

    if (left_index>right_index) return nullptr;

    TreeNode *p = new TreeNode(nums[middle_index]);
    if (!root) root = p;

    int left_left= left_index; int left_right = middle_index-1;
    TreeNode *left_node = traversal(nums,left_left,left_right);

    int right_left=middle_index+1; int right_right= right_index;
    TreeNode *right_node = traversal(nums,right_left,right_right);

    p->left = left_node;
    p->right = right_node;
    return p;

}
