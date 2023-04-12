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
    // ����Ҫͬʱ�������յ� ֻ��Ҫ�ҵ����ֵ next �������
    while (cur != head) // ѭ����һȦ���������  ���������ɴ�С�ı仯  Ҳ����˵��ʹ�����˴Ӵ�С Ҳ����תȦ
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


