/*
@File  :450.cpp
@Author:dfc
@Date  :2022/10/17  17:09
@Desc  : 删除二叉搜索树的节点
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
// 递归的写法
TreeNode* deleteNode(TreeNode* root, int key) // 返回的是删除后需要接上去的节点
{
    if (root== nullptr) return root;
    if (root->val == key and root->left== nullptr and root->right == nullptr)
    {
        delete root;
        return nullptr;
    }
    if (root->val == key and root->left!= nullptr and root->right== nullptr)
    {
        auto p = root->left;
        delete root;
        return p;
    }
    if (root->val == key and root->right != nullptr and root->left== nullptr)
    {
        TreeNode *p_node = root->right;
        delete root;
        return p_node;
    }
    if (root->val == key and root->left and root->right)
    {
        TreeNode *left_node = root->left;
        TreeNode *right_node = root->right;
        TreeNode *p = right_node;
        while (p->left)
            p = p->left;
        p->left = left_node;
        delete root;
        return right_node;
    }

    TreeNode *result;
    if (root->val > key)
    {
        result = deleteNode(root->left,key);
        root->left = result; // 把节点接回去
    }
    else if (root->val <key)
    {
        result = deleteNode(root->right,key);
        root->right = result;
    }
    return root;

}*/

// 迭代的写法
TreeNode* deleteNode(TreeNode* root, int key)
{
    TreeNode *cur=root;
    TreeNode *last_node = nullptr;
    int flag=0;

    if (!root) return root;

    while (cur)
    {
        TreeNode *p= nullptr;
        if (cur->val == key)
        {
            if (cur->val == key and cur->left == nullptr and cur->right== nullptr)
                p= nullptr;
            else if (cur->val == key and cur->left!= nullptr and cur->right == nullptr)
            {
                p = cur->left;
            }
            else if (cur->val == key and cur->left== nullptr and cur->right != nullptr)
            {
                p = cur->right;
            }
            else if (cur->val == key and cur->left!= nullptr and cur->right != nullptr)
            {
                TreeNode *left_node = cur->left;
                TreeNode *right_node = cur->right;
                TreeNode *tpm = right_node;
                while (tpm->left)
                    tpm = tpm->left;
                tpm->left = left_node;
                p = right_node;
            }
            if (flag==1) last_node->left = p;
            else if (flag==2) last_node->right= p;
            else if (flag==0) return p;  // 这是对应那种一来就删除 没有前节点来接应，只有把待接应的节点直接返回
            delete cur;
            return root;
        }


        else if (cur->val > key)
        {
            last_node = cur;
            cur = cur->left;
            flag =1;
        }
        else if (cur->val <key)
        {
            last_node = cur;
            cur = cur->right;
            flag = 2;
        }

    }
    return root;
}