/*
@File  :offer_18.cpp
@Author:dfc
@Date  :2022/12/13  19:44
@Desc  : ɾ������Ľڵ�
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
    ListNode *first = new ListNode(0); // ����һ��Ҫnew ��Ϊfirstֻ��һ��ָ�� ���ڻ���ָ���κνڵ� ��Ȼ��һ���Ҫ����
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