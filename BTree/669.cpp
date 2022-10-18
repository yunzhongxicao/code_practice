/*
@File  :669.cpp
@Author:dfc
@Date  :2022/10/18  10:39
@Desc  : �޼�����������
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
 * �ݹ�Ľⷨ
TreeNode* trimBST(TreeNode* root, int low, int high) // ���ص����޼�����Ҫ����ȥ�Ľڵ�
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

// ������˼·��֮ǰ��̫һ�� �����ҷֿ�����
// ��Ϊ�漰������һ����
TreeNode* trimBST(TreeNode* root, int low, int high)
{
    if (!root) return root;

    TreeNode *cur;
    TreeNode *last_node;

    while (root) // �Ѹ��ڵ�ŵ������У���Ϊ��������ֿ��������ҽڵ��ʱ��ֻ��Ҫ�ж�һ����У���߿϶����ұ�lowС�ģ��ұ߿϶����ұ�high���
    {
        if (root->val <low) root =root->right;
        else if (root->val >high) root = root->left;
        else break;
    }

    cur = root; // �����С�Ĵ������ֻ��Ҫһ·��������� ��Ȼ���ҵ��������
    while (cur)
    {
        while (cur->left and cur->left->val < low) // ע��������while ����if ��Ҫһֱѭ�� ֱ���ҵ����������� Ȼ�����ȥ
                                                    // ��Ϊ�����if ��ôÿ��ѭ����ʱ�� cur ���Ѿ��ı���
                                                    // �������Ŀ��ֻ�Ǹı�cur->left ���ܸı�cur ֱ���ҵ��˷��������� �ٰ�cur��ֵ����
            cur->left = cur->left->right;

        cur = cur->left;
    }

    cur = root;
    while (cur)  // һ·�����ң������highС����ô��������ȻҲ���㣬���������ң������high�����������������ˣ�����������һ�����������Ľ���ȥ
    {
        while (cur->right and cur->right->val > high) //
            cur->right = cur->right->left;
        cur= cur->right;
    }
    return root;

}



