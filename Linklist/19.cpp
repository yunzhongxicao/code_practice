/*
@File  :19.cpp
@Author:dfc
@Date  :2022/8/28  10:38
@Desc  : 删除链表倒数第n个节点
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

// 这种倒数的都可以用两个指针来解决，将整个长度分为两段，第一个先走n步，然后两个一起走
// 那么第二个剩下的就应该和第一个先走的n步是一样的

ListNode* removeNthFromEnd(ListNode* head, int n);

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode* dummy_head = new ListNode(0);
    dummy_head->next = head;
    ListNode* fast_node = dummy_head;
    ListNode* slow_node = dummy_head;
    int count = 0;
    while (count<n)
    {
        fast_node = fast_node->next;
        count++;
    }
    // 此时fast_node走了n步
    while (fast_node->next!=NULL)
    {
        fast_node = fast_node->next;
        slow_node = slow_node->next;
    }
    ListNode* tmp = slow_node->next;
    slow_node->next = tmp->next;
    delete  tmp;

    return dummy_head->next;
}

