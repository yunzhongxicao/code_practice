/*
@File  :offer_18.cpp
@Author:dfc
@Date  :2022/12/13  19:44
@Desc  : 删除链表的节点
*/
#include "iostream"
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteNode(ListNode* head, int val)
{
    ListNode *first = new ListNode(0); // 这里一定要new 因为first只是一个指针 现在还不指向任何节点 不然下一句就要报错
    first->next = head;
    ListNode *p=first;
    while (p->next != nullptr)
    {
        if (p->next->val== val)
        {
            p->next = p->next->next;
            break;
        }
        p = p->next;
    }
    return first->next;
}