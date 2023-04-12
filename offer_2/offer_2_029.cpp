/*
@File  :offer_2_029.cpp
@Author:dfc
@Date  :2023/4/11  19:10
@Desc  :
*/
#include "iostream"
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(){};
    Node(int  x){
        val = x;
        next = nullptr;
    }
};

Node* insert(Node* head, int insertVal)
{
    if (!head)
    {
        Node *cur = new Node(insertVal);
        cur ->next = cur;
        return cur;
    }
    if (head->next == head)
    {
        Node *cur = new Node(insertVal);
        head->next = cur;
        cur->next =head;
        return head;
    }
    Node *cur = head->next;
    Node *last = head;
    while (true)
    {
        if (insertVal>=last->val and insertVal <= cur->val)
        {
            Node *temp = new Node(insertVal);
            last->next = temp;
            temp->next = cur;
            return head;
        }
        last = cur;
        cur = cur->next;
    }
    return head;
}


