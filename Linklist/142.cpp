/*
@File  :142.cpp
@Author:dfc
@Date  :2022/8/28  11:55
@Desc  : »·ĞÎÁ´±í
*/

#include "iostream"
#include "vector"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *detectCycle(ListNode *head);

ListNode *detectCycle(ListNode *head)
{
    ListNode* fast_node = head;
    ListNode* slow_node = head;
    while (fast_node!=NULL and fast_node->next!=NULL)
    {
        fast_node = fast_node->next->next;
        slow_node = slow_node->next;
        if (fast_node== slow_node)
        {
            ListNode* index1 = fast_node;
            ListNode* index2 = head;
            while (index1 != index2)
            {
                index2 = index2->next;
                index1 = index1 ->next;
            }
            return index1;
        }
    }
}

