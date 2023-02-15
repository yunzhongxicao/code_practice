/*
@File  :142_second.cpp
@Author:dfc
@Date  :2023/2/14  18:09
@Desc  : »·ÐÎÁ´±í
*/
#include "iostream"

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){};
};

ListNode *detectCycle(ListNode *head)
{
    ListNode *fast=head;
    ListNode *slow = head;
    while (fast->next and fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow==fast)
        {
            ListNode *p = head;
            while (slow!=p)
            {
                p = p->next;
                slow = slow->next;
            }
            return slow;
        }
    }
    return nullptr;
}


