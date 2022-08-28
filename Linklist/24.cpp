/*
@File  :24.cpp
@Author:dfc
@Date  :2022/8/28  10:10
@Desc  : 两两交换链表中的节点
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

ListNode* swapPairs(ListNode* head);

ListNode* swapPairs(ListNode* head)
{
    ListNode* dummy_head = new ListNode(0);
    dummy_head->next = head;
    ListNode* first_node;
    ListNode* second_node;
    ListNode* cur = dummy_head;
    while (cur->next!=NULL and cur->next->next!=NULL)
    {

        first_node = cur->next;
        second_node = first_node->next;
        ListNode* tmp = second_node->next;
        cur->next = second_node;
        second_node->next = first_node;
        first_node->next = tmp;
        cur = cur->next->next;
    }
    return dummy_head->next;
}
