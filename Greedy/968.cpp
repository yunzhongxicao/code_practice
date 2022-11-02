/*
@File  :968.cpp
@Author:dfc
@Date  :2022/11/2  11:32
@Desc  : 监控二叉树
*/
#include "iostream"
#include "vector"
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int result=0;
// 0: 不可观察 1： 有相机 2： 可观但无相机
int traversal(TreeNode* cur) // 采用的是后序遍历 需要把自己的状态给父节点报告，一个节点要接收两个子节点的状态，来决定自己的状态，并向上报告
{
    if (cur == NULL) return 2;
    int left = traversal(cur->left);
    int right = traversal(cur->right);
    if (left==2 and right==2) return 0; // 此时不可观 但是相机不应该装在这里
    if (left==0 or right==0) // 有孩子不可观  就要装相机 注意这里的顺序要放在后面if的前面
    {
        result++;
        return 1;
    }
    if (left==1 or right==1) return 2; // 可以画个图 一共9中情况 看一下还剩哪些情况
    return -1; // 不会走到这里
}

int minCameraCover(TreeNode* root)
{
    int last_result = traversal(root);
    if (last_result==0) result++;
    return result;
}




