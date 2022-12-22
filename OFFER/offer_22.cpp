/*
@File  :offer_22.cpp
@Author:dfc
@Date  :2022/12/19  10:58
@Desc  :链表中倒数第k个节点
*/
#include "iostream"
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getKthFromEnd(ListNode* head, int k)
{
    ListNode *fast, *slow;
    ListNode *first = new ListNode(0);
    first->next = head;
    fast= first;
    slow = head;
    while (fast!= nullptr and k>0)
    {
        fast = fast->next;
        k--;
    }
    while (fast->next!= nullptr )
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
