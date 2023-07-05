/*
@File  :offer_2_050.cpp
@Author:dfc
@Date  :2023/7/3  23:00
@Desc  :
*/
#include "iostream"
#include "vector"
#include "queue"
#include "unordered_map"

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(nullptr),right(nullptr){};
};

long long sum =0;
int count =0;
unordered_map<long long, int> my_map;

void dfs(TreeNode *root,int targetSum)
{
    sum += root->val;
    long long  diff = sum - targetSum;
    if (my_map.find(diff) != my_map.end())
    {
        count += my_map[diff];
    }
    my_map[sum]++;
    if (root->left)
    {
        dfs(root->left,targetSum);
        my_map[sum] --;
        sum -= root->left->val;
    }
    if (root->right)
    {
        dfs(root->right,targetSum);
        my_map[sum] --;
        sum -= root->right->val;
    }
}

int pathSum(TreeNode* root, int targetSum)
{
    my_map[0] = 1;
    if (!root) return 0; // 这个只在最开始判断一次 后面就不会传空的进去了
    dfs(root,targetSum);
    return count;
}
