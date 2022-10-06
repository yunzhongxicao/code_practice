/*
@File  :101.cpp
@Author:dfc
@Date  :2022/10/6  15:45
@Desc  :对称二叉树
*/

#include "iostream"
#include "stack"
#include "vector"
#include "queue"

using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
public:
    TreeNode(){val=0;left=NULL;right=NULL;};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

bool isSymmetric(TreeNode* root);

bool compare(TreeNode* left_node,TreeNode* right_node);


/* 这是一种比较典型的错误写法 注意 要比较的是两个树是不是对称 不是左右节点
 * 这种写法的问题在于 递归到最后会比较某一个根下面的左右节点是否相等，但是其实应该是比较对称那一侧的是否相等
 * 再理解一下就是 是要比较一个节点的左右两棵树是否相等，所以传入的参数应该是左右两个节点
 * 如果只传入t 就是看t->left这棵树是不是对称的 明显不对
bool compare(TreeNode* t)
{
    if (t==NULL) return true;
    else if (t->left!=NULL and t->right==NULL) return false;
    else if (t->left == NULL and t->right!=NULL) return false;
    else if (t->left == NULL and t->right == NULL) return true;
    bool left_flag,right_flag;
    left_flag = compare(t->left);
    right_flag = compare(t->right);
    if (left_flag and right_flag and t->left->val == t->right->val)
        return true;
    else return false;
}

bool isSymmetric(TreeNode* root)
{
    return compare(root);
}*/


/* 这是递归的写法
bool compare(TreeNode* left_node,TreeNode* right_node)
{
    if (left_node==NULL and right_node==NULL) return true;
    else if (left_node==NULL and right_node!= NULL) return false;
    else if (left_node!=NULL and right_node==NULL) return false;
    else if (left_node->val != right_node->val) return false;

    bool left_flag,right_flag;

    left_flag = compare(left_node->left,right_node->right);
    right_flag = compare(left_node->right,right_node->left);

    if (left_flag && right_flag)
        return true;
    else return false;

}

bool isSymmetric(TreeNode* root)
{
    if (!root) return true;
    return compare(root->left,root->right);
}*/


bool isSymmetric(TreeNode* root) // 非递归的写法
{
    // 注意 这里主要是用队列 模仿层序遍历
    // 主要的目的就是将需要比较的元素放到一起压进去，所以是一次压两个进去 然后弹出去也是一次弹两个
    queue<TreeNode*> my_queue;

    if (!root) return true;

    my_queue.push(root->left);
    my_queue.push(root->right);

    while (!my_queue.empty())
    {
        TreeNode *left_node,*right_node;
        left_node = my_queue.front();my_queue.pop();
        right_node = my_queue.front(); my_queue.pop();

        if (right_node== NULL and left_node==NULL) continue; /// 注意 这里的写法和递归不一样了
        else if (left_node==NULL and right_node!= NULL) return false;
        else if (left_node!=NULL and right_node==NULL) return false;
        else if (left_node->val != right_node->val) return false;

        my_queue.push(left_node->left);
        my_queue.push(right_node->right);
        my_queue.push(left_node->right);
        my_queue.push(right_node->left);
    }
    return true;
}
