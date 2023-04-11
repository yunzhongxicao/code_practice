/*
@File  :offer_2_028.cpp
@Author:dfc
@Date  :2023/4/11  9:35
@Desc  :
*/
#include "iostream"
#include "vector"
using namespace std;

//struct ListNode{
//    int val;
//    ListNode *next;
//    ListNode(int x):val(x),next(nullptr){};
//};

struct Node{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

Node* dfs(Node * father) // 返回的是这个father 的child的尾部指针  第一种写法
{
    Node *pre =father;
    while (father)
    {
        Node * temp = father->next;
        if (father->child)
        {
            father->next = father->child;
            father->child->prev = father;
            Node *end = dfs(father->child);
            if (temp)
            {
                end->next = temp;
                temp->prev = end;
            }
            father->child = nullptr;
        }

        pre = father;
        father = temp;

    }
    while (pre->next)
    {
        pre = pre->next;
    }
    return pre;
}

Node* dfs(Node * father) // 返回的是这个father 的child的尾部指针  第二种写法
{
    Node *pre =father;
    while (father)
    {
        Node * temp = father->next;
        if (father->child)
        {
            father->next = father->child;
            father->child->prev = father;
            Node *end = dfs(father->child);
            if (temp)
            {
                end->next = temp;
                temp->prev = end;
            }
            father->child = nullptr;
            pre = end;
            father =temp;
        }
        else{
            pre = father;
            father = temp;
        }
    }
    return pre;
}


Node* flatten(Node* head)
{
    Node *p = head;
    dfs(p);
    p =head;
    while (p)
    {
        cout<<p->val;
        p = p->next;
    }
    return head;
}