/*
@File  :offer_2_027.cpp
@Author:dfc
@Date  :2023/4/11  9:02
@Desc  :
*/
#include "iostream"
#include "stack"
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(nullptr){};
};
bool isPalindrome(ListNode* head)
{
    stack<ListNode*> my_stack;
    ListNode *p= head;
    while (p)
    {
        my_stack.push(p);
        p= p->next;
    }
    ListNode *start= head;
    ListNode *end ;
    while (start!= nullptr)
    {
        end = my_stack.top();
        if (start->val == end->val)
        {
            start = start->next;
            my_stack.pop();
//            end = my_stack.top();
        }
        else
            return false;
    }
    return true;
}