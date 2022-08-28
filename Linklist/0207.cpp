/*
@File  :0207.cpp
@Author:dfc
@Date  :2022/8/28  11:03
@Desc  : 链表相交
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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode* cur_A = headA;
    ListNode* cur_B = headB;
    int len_A = 0;
    int len_B = 0;
    while (cur_A != NULL)
    {
        len_A++;
        cur_A = cur_A->next;
    }
    while (cur_B != NULL)
    {
        len_B++;
        cur_B = cur_B->next;
    }
    cur_A = headA;
    cur_B = headB;
    // 让curA为最长链表的头，lenA为其长度
    if (len_B>len_A)
    {
        swap(len_A,len_B);
        swap(cur_A,cur_B);
    }
    int dif = len_A-len_B;
    while (dif>0)
    {
        cur_A= cur_A->next;
        dif--;
    }
    while (cur_A != NULL)
    {
        if (cur_A == cur_B)
            return cur_A;
        cur_A = cur_A->next;
        cur_B = cur_B->next;
    }
    return NULL;
}
