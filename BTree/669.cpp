/*
@File  :669.cpp
@Author:dfc
@Date  :2022/10/18  10:39
@Desc  : 修剪二叉搜索树
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
 * 递归的解法
TreeNode* trimBST(TreeNode* root, int low, int high) // 返回的是修剪后需要接上去的节点
{
    if (!root) return root;

    if (root->val < low)
    {
        TreeNode *right_node= trimBST(root->right,low,high);
        return right_node;
    }
    else if (root->val >high)
    {
        TreeNode *left_node = trimBST(root->left,low,high);
        return left_node;
    }
    else
    {
        TreeNode *left_node = trimBST(root->left,low,high);
        TreeNode *right_node = trimBST(root->right,low,high);
        root->left = left_node;
        root->right = right_node;
        return root;
    }
}*/

// 迭代的思路和之前不太一样 是左右分开处理
// 因为涉及到左右一起连
TreeNode* trimBST(TreeNode* root, int low, int high)
{
    if (!root) return root;

    TreeNode *cur;
    TreeNode *last_node;

    while (root) // 把根节点放到区间中，是为了让下面分开处理左右节点的时候只需要判断一侧就行，左边肯定是找比low小的，右边肯定是找比high大的
    {
        if (root->val <low) root =root->right;
        else if (root->val >high) root = root->left;
        else break;
    }

    cur = root; // 把左边小的处理掉，只需要一路向左遍历， 必然能找到不满足的
    while (cur)
    {
        while (cur->left and cur->left->val < low) // 注意这里是while 不是if 是要一直循环 直到找到满足条件的 然后接上去
                                                    // 因为如果是if 那么每次循环的时候 cur 就已经改变了
                                                    // 而这里的目的只是改变cur->left 不能改变cur 直到找到了符合条件的 再把cur赋值过来
            cur->left = cur->left->right;

        cur = cur->left;
    }

    cur = root;
    while (cur)  // 一路向右找，如果比high小，那么左子树必然也满足，继续向右找；如果比high大，右子树都不能用了，从左子树找一个符合条件的接上去
    {
        while (cur->right and cur->right->val > high) //
            cur->right = cur->right->left;
        cur= cur->right;
    }
    return root;

}



