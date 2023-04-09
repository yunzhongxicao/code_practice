/*
@File  :offer_2_022.cpp
@Author:dfc
@Date  :2023/4/9  14:46
@Desc  :
*/
#include "iostream"
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(nullptr){};
};

ListNode *detectCycle(ListNode *head)
{
    ListNode *fast=head, *slow = head;
    while (fast)
    {
        slow = slow->next;
        if (fast->next== nullptr) return nullptr;
        fast = fast->next->next;
        if (slow==fast)
            break;
    }
    if (!fast) return nullptr;
    slow = head;
    while (slow)
    {
        if (slow==fast) return slow;
        slow = slow->next;
        fast = fast->next;
    }
    return nullptr;
}