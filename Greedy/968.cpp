/*
@File  :968.cpp
@Author:dfc
@Date  :2022/11/2  11:32
@Desc  : ��ض�����
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
// 0: ���ɹ۲� 1�� ����� 2�� �ɹ۵������
int traversal(TreeNode* cur) // ���õ��Ǻ������ ��Ҫ���Լ���״̬�����ڵ㱨�棬һ���ڵ�Ҫ���������ӽڵ��״̬���������Լ���״̬�������ϱ���
{
    if (cur == NULL) return 2;
    int left = traversal(cur->left);
    int right = traversal(cur->right);
    if (left==2 and right==2) return 0; // ��ʱ���ɹ� ���������Ӧ��װ������
    if (left==0 or right==0) // �к��Ӳ��ɹ�  ��Ҫװ��� ע�������˳��Ҫ���ں���if��ǰ��
    {
        result++;
        return 1;
    }
    if (left==1 or right==1) return 2; // ���Ի���ͼ һ��9����� ��һ�»�ʣ��Щ���
    return -1; // �����ߵ�����
}

int minCameraCover(TreeNode* root)
{
    int last_result = traversal(root);
    if (last_result==0) result++;
    return result;
}




