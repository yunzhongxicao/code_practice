/*
@File  :0207_second.cpp
@Author:dfc
@Date  :2023/2/12  14:13
@Desc  : 链表相交
*/
#include "iostream"
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){};
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *p1 = headA;
    ListNode *p2= headB;
    int n1=0,n2=0;
    while (p1)
    {
        p1 = p1->next;
        n1++;
    }
    while (p2)
    {
        p2 = p2->next;
        n2++;
    }
    if (n1<=n2)
    {
        p1 = headA;
        p2 = headB;
    } else // p1 是短的起点
    {
        p1 = headB;
        p2 = headA;
    }
    int diff = abs(n1-n2);
    int count = 0;
    while (count<diff)
    {
        p2 = p2->next;
        count++;
    }
    while (p1)
    {
        if (p1==p2)return p1;
        p1 = p1->next;
        p2 = p2->next;
    }
    return nullptr;
}

