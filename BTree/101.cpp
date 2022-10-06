/*
@File  :101.cpp
@Author:dfc
@Date  :2022/10/6  15:45
@Desc  :�Գƶ�����
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


/* ����һ�ֱȽϵ��͵Ĵ���д�� ע�� Ҫ�Ƚϵ����������ǲ��ǶԳ� �������ҽڵ�
 * ����д������������ �ݹ鵽����Ƚ�ĳһ������������ҽڵ��Ƿ���ȣ�������ʵӦ���ǱȽ϶Գ���һ����Ƿ����
 * �����һ�¾��� ��Ҫ�Ƚ�һ���ڵ�������������Ƿ���ȣ����Դ���Ĳ���Ӧ�������������ڵ�
 * ���ֻ����t ���ǿ�t->left������ǲ��ǶԳƵ� ���Բ���
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


/* ���ǵݹ��д��
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


bool isSymmetric(TreeNode* root) // �ǵݹ��д��
{
    // ע�� ������Ҫ���ö��� ģ�²������
    // ��Ҫ��Ŀ�ľ��ǽ���Ҫ�Ƚϵ�Ԫ�طŵ�һ��ѹ��ȥ��������һ��ѹ������ȥ Ȼ�󵯳�ȥҲ��һ�ε�����
    queue<TreeNode*> my_queue;

    if (!root) return true;

    my_queue.push(root->left);
    my_queue.push(root->right);

    while (!my_queue.empty())
    {
        TreeNode *left_node,*right_node;
        left_node = my_queue.front();my_queue.pop();
        right_node = my_queue.front(); my_queue.pop();

        if (right_node== NULL and left_node==NULL) continue; /// ע�� �����д���͵ݹ鲻һ����
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
