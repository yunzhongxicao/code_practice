/*
@File  :2.cpp
@Author:dfc
@Date  :2023/3/27  11:56
@Desc  :
*/
#include "iostream"
using namespace std;
struct ListNode{
    int  val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){};
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode *p1 = l1, *p2=l2;
    ListNode * new_node= l1;
    ListNode * last_node = new_node;
    int add =0;

    while (p1 and p2)
    {
        int  temp1 = p1->val, temp2 = p2->val;
        int val = (temp1+temp2 + add) % 10;
        new_node->val = val;
        cout<<new_node->val<<" ";

        last_node = new_node;
        p1 = p1->next;
        p2 = p2->next;
        new_node = p1;
        add = (temp1+temp2 + add) / 10;
    }
    if (p1== nullptr)
        last_node->next = p2;
    else last_node->next = p1;
    new_node = last_node->next;
    while (new_node)
    {
        int temp = new_node->val;
        new_node ->val = (temp+add) % 10;
        cout<<new_node->val<<" ";
        add = (temp+add) / 10;
        new_node = new_node->next;
        last_node = new_node;
    }
    if (add==1)
    {
        ListNode * final_node = new ListNode(1);
        last_node->next = final_node;
    }
    return l1;
}

