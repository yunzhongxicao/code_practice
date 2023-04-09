/*
@File  :offer_2_023.cpp
@Author:dfc
@Date  :2023/4/9  14:32
@Desc  :
*/
#include "iostream"
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(nullptr){};
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *p1 = headA;
    int count_1= 0 ;
    while (p1)
    {
        p1 = p1 ->next;
        count_1++;
    }
    ListNode * p2 = headB;
    int count_2 = 0;
    while (p2)
    {
        p2 = p2->next;
        count_2++;
    }
    int k;
    ListNode * first, *second;
    if (count_1>count_2)
    {
        first = headA;
        second = headB;
        k = count_1 - count_2;
    }
    else
    {
        first = headB;
        second = headA;
        k = count_2 - count_1;
    }
    while (k>0)
    {
        first = first->next;
        k--;
    }
    while (first and second)
    {
        if (first==second) return first;
        first = first->next;
        second = second->next;
    }
    return nullptr;
}

