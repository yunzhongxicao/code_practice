/*
@File  :offer_2_024.cpp
@Author:dfc
@Date  :2023/4/9  14:59
@Desc  :
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
    ListNode *pre = nullptr, *cur = head;
    ListNode *last;
    while (cur)
    {
        last = cur->next;
        cur->next = pre;
        pre = cur;
        cur  = last;
    }
    return pre;
}
