/*
@File  :206_second.cpp
@Author:dfc
@Date  :2023/2/12  11:43
@Desc  :·´×ªÁ´±í
*/
#include "iostream"
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(nullptr){};
};

ListNode* reverseList(ListNode* head)
{
    if (!head) return head;
    ListNode *pre = nullptr;
    ListNode *cur = head;
    while (cur)
    {
        ListNode *last = cur->next;
        cur->next = pre;
        pre = cur;
        cur = last;
    }
    return pre;
}
