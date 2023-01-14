/*
@File  :offer_52.cpp
@Author:dfc
@Date  :2023/1/13  16:02
@Desc  : 两个链表的第一个公共节点
*/
#include "iostream"
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)  // 方法1
{
    if (headA== nullptr or headB== nullptr) return nullptr;
    int countA=0;
    ListNode *p = headA;
    while (p)
    {
        countA++;
        p = p->next;
    }
    int countB = 0;
    p = headB;
    while (p)
    {
        countB++;
        p = p->next;
    }
    ListNode *p_A=headA, *p_B = headB;
    if (countA>countB)
    {
        int temp = countA-countB;
        while (temp>0)
        {
            p_A = p_A->next;
            temp--;
        }
    }
    else
    {
        int temp = countB-countA;
        while (temp>0)
        {
            p_B = p_B->next;
            temp--;
        }
    }
    while (p_A)
    {
        if (p_A==p_B) return p_A;
        p_A = p_A->next;
        p_B = p_B->next;
    }
    return nullptr;
}*/

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == nullptr or headB== nullptr) return nullptr;
    ListNode *a = headA, *b = headB;
    while (a!=b)
    {
        a = a== nullptr?headB:a->next; // 只会判断一次为空 就是把自己走完 第二次为空就相等了
        b = b== nullptr?headA:b->next;
    }
    return a;
}