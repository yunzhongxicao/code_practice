/*
@File  :116.cpp
@Author:dfc
@Date  :2022/10/5  19:41
@Desc  :填充每个节点的下一个右侧节点指针
*/

#include "iostream"
#include "stack"
#include "vector"
#include "queue"
#include "algorithm"

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root)
{
    queue<Node*> my_queue;

    Node *p;

    if (!root) return root;

    my_queue.push(root);

    while (!my_queue.empty())
    {
        int size = my_queue.size();

        for (int i = 0; i < size; ++i) {
            p = my_queue.front();
            my_queue.pop();
            if (i<size-1)
            {
                p->next = my_queue.front();
            }
            if (p->left) my_queue.push(p->left);
            if (p->right) my_queue.push(p->right);
        }
    }
    return root;


}




