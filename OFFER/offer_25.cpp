/*
@File  :offer_25.cpp
@Author:dfc
@Date  :2022/12/22  16:23
@Desc  : 合并两个排序的链表
*/
#include "iostream"
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    ListNode *p1 = l1, *p2 = l2;
    auto *head = new ListNode(0);
    ListNode *cur = head;
    while (p1!= nullptr and p2 != nullptr)
    {
        if (p1->val>=p2->val)
        {
            cur->next = p2;
            p2 = p2->next;
            cur = cur->next;
        }
        else
        {
            cur->next = p1;
            p1 = p1->next;
            cur = cur->next;
        }
    }
    if (p1== nullptr)
        cur->next = p2;
    else cur->next = p1;
    return head->next;
}

