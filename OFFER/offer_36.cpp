/*
@File  :offer_36.cpp
@Author:dfc
@Date  :2022/12/26  21:08
@Desc  : 二叉搜索树与双向链表
*/
#include "iostream"
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

Node *last_node = nullptr, *left_node,*right_node;
void traverse(Node *p);
Node* treeToDoublyList(Node* root)
{
    if (!root) return root;
/*    Node *left_node= root;
    while (left_node->left)
    {
        left_node = left_node->left;
    }
    Node *right_node = root;
    while (right_node->right)
    {
        right_node = right_node->right;
    }*/
    traverse(root);
    right_node = last_node;

    left_node->left = right_node;
    right_node->right = left_node;
    return left_node;
}

void traverse(Node *p)
{
    if (p== nullptr) return;
    traverse(p->left);
    if (last_node== nullptr)
    {
        last_node= p;
        left_node = p;
    }
    else
    {
        p->left = last_node;
        last_node->right=p;
        last_node = p;
    }
    traverse(p->right);
}
