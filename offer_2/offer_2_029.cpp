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
    int max_value = head->val;
    Node *cur = head->next;
    Node *end=head;
    // 不需要同时找起点和终点 只需要找到最大值 next 就是起点
    while (cur != head) // 循环了一圈如何跳出来  而不是找由大到小的变化  也就是说即使发现了从大到小 也继续转圈
    {
        if (cur->val>=max_value)
        {
            max_value = cur->val;
            end = cur;
            cur = cur->next;
        }
        else
            cur = cur->next;
    }
    Node *start = end->next;
    if (insertVal>= end->val or  insertVal <= start->val)
    {
        Node *temp  = new Node(insertVal);
        end ->next = temp;
        temp->next = start;
        return head;
    }
    cur = start;
    Node *last = end;
    while (true)
    {
        if (insertVal>=cur->val and insertVal>= last->val)
        {
            Node *temp = new Node(insertVal);
            last->next =temp;
            temp->next = cur;
            return head;
        }
        last = cur;
        cur = cur->next;
    }
    return head;
}


