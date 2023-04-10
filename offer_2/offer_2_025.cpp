/*
@File  :offer_2_025.cpp
@Author:dfc
@Date  :2023/4/10  10:16
@Desc  :
*/
#include "iostream"
#include "vector"
#include "stack"
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){};
};

ListNode* trans(ListNode *head)
{
    ListNode *pre = nullptr;
    ListNode *cur = head;
    ListNode *last;
    while (cur)
    {
        last = cur->next;
        cur->next = pre;
        pre = cur;
        cur = last;
    }
    return pre;
}

/*
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode *new_l1 = trans(l1);
    ListNode *new_l2 = trans(l2);
    ListNode *p1 = new_l1, *p2 = new_l2;
    int carry= 0;
    ListNode *dummy_head = new ListNode(0);
    dummy_head->next = new_l1;
    ListNode *pre = dummy_head;
    while (p1 and p2)
    {
        int temp= p1->val + p2->val+carry;
        p1->val = temp % 10; // 用p1来存新链表
        pre = p1;
        p1 = p1->next;
        p2 = p2->next;
        carry = temp / 10;
    }
    if (!p2)
        pre->next = p1;
    else if (!p1)
        pre->next = p2;
    p1 = pre->next;
    while (p1)
    {
        int temp  = p1->val + carry;
        p1->val = temp % 10;
        pre = p1;
        p1 = p1->next;
        carry = temp / 10;
    }
    if (carry==1)
    {
        ListNode *temp = new ListNode(1);
        pre->next = temp;
    }
    delete dummy_head;
    ListNode * result = trans(new_l1);
    return result;
}*/

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    stack<int> s1;
    while (l1)
    {
        s1.push(l1->val);
        l1 = l1->next;
    }
    stack<int> s2;
    while (l2)
    {
        s2.push(l2->val);
        l2 = l2->next;
    }
    int carry = 0;
    ListNode *last_node = nullptr;
    while (!s1.empty() or !s2.empty())
    {
        int a = s1.empty()?0:s1.top();
        int b = s2.empty()?0:s2.top();
        int temp = a+b+carry;
        ListNode *cur = new ListNode(temp % 10);
        cur->next = last_node;
        last_node = cur;
        if(!s1.empty() )s1.pop();
        if(!s2.empty()) s2.pop();
        carry = temp /10;
    }
    if (carry==1) {
        ListNode *cur = new ListNode(1);
        cur->next = last_node;
        last_node = cur;
    }
    return last_node;
}
