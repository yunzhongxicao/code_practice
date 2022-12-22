/*
@File  :24.cpp
@Author:dfc
@Date  :2022/12/19  12:42
@Desc  : ·´×ªÁ´±í
*/
#include "iostream"
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head)
{
    ListNode *pre= nullptr;
    ListNode *cur = head;
    ListNode *next_node;
    while (cur != nullptr)
    {
        next_node = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next_node;
    }
    return pre;
}