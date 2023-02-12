/*
@File  :19_second.cpp
@Author:dfc
@Date  :2023/2/12  13:49
@Desc  :删除链表的倒数第 n个节点
*/
#include "iostream"
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(nullptr){};
};

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode *first_node = new ListNode(0);
    first_node->next = head;
    ListNode *fast= first_node;
    ListNode *slow = first_node;
    int count =0;
    while (count<n)
    {
        fast = fast->next;
        count++;
    }
    while (fast->next) // 同时开走
    {
        fast = fast->next;
        slow = slow->next;
    }
    // 找到要删除的前一个
    ListNode *temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
    return first_node->next;
}
