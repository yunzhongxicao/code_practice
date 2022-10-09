/*
@File  :110.cpp
@Author:dfc
@Date  :2022/10/9  11:32
@Desc  : ƽ�������
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
int get_height(TreeNode *t);
bool isBalanced(TreeNode* root)
{
    if (!root) return true;
    bool flag ;
    return get_height(root) != -1;
}

int get_height(TreeNode *t)  // �����߶ȵĹ����Ѿ�����һ������ˣ����������жϲ������߱�����
{
    if (!t) return 0;
    int left_height = get_height(t->left);

    if (left_height==-1) return -1;  // ����������߶�Ϊ-1 ��ô���ڵ�ĸ߶Ⱦ�ֱ��Ϊ-1  �����Ϳ����ò�ƽ���������һ·���ϴ���ȥ
                                    // ������root�ڵ�ĸ߶� ����в�ƽ�������  �Ϳ���һ·����ȥ ʹ��Ϊ-1

    int right_height = get_height(t->right);

    if (right_height==-1) return -1;


    if (abs(left_height-right_height)>=2) return -1;  // ������������߶Ȳ����2 �Ǿ��ø��ڵ�߶�Ϊ-1 ��������ƽ����
    else return 1+max(left_height,right_height);

}
