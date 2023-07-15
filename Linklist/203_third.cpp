/*
@File  :203_third.cpp
@Author:dfc
@Date  :2023/7/14  23:08
@Desc  :
*/
#include "iostream"

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(nullptr){};
};

ListNode* removeElements(ListNode* head, int val)
{
    ListNode *dummy_head = new ListNode(-1);
    dummy_head->next = head;
    ListNode * pre = dummy_head;
    ListNode *cur = pre->next;
    while (cur)
    {
        if (cur->val==val)
        {
            pre->next = cur->next;
            cur = pre ->next;
        }
        else
        {
            pre =  cur;
            cur = cur->next;
        }
    }
    return dummy_head->next;
}

