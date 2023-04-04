/*
@File  :offer_2_021.cpp
@Author:dfc
@Date  :2023/4/4  18:38
@Desc  :
*/
#include "iostream"
#include "vector"
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){};
};

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode * dummy_head = new ListNode(0);
    dummy_head->next = head;
    int count = 0;
    ListNode *fast = dummy_head;
    while (count<n)
    {
        fast = fast->next;
        count++;
    }
    ListNode *slow = dummy_head;
    while (fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }
    ListNode *temp = slow->next;
    slow->next = temp->next;
    delete temp;
    return dummy_head->next;
}

