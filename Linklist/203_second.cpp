/*
@File  :203_second.cpp
@Author:dfc
@Date  :2023/2/11  14:53
@Desc  :
*/
#include "iostream"
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){};
};

ListNode* removeElements(ListNode* head, int val)
{
    ListNode *first_nodex = new ListNode(0  );
    first_nodex->next = head;
    ListNode *p = first_nodex;
    while (p->next!= nullptr)
    {
        if (p->next->val == val)
        {
            ListNode *temp = p->next;
            p->next = temp->next;
            delete temp;
        }
        else
            p = p->next;
    }
    return first_nodex->next;
}
