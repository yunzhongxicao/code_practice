/*
@File  :offer_2_026.cpp
@Author:dfc
@Date  :2023/4/10  14:25
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

void reorderList(ListNode* head)
{
    stack<ListNode*> my_stack;
    ListNode *p = head;
    while (p)
    {
        my_stack.push(p);
        p = p->next;
    }
    ListNode *cur = head;
    ListNode *last = cur->next;
    if (!last) return; // 防止只有一个节点 last 直接为空 后面就都不会为空了
    ListNode *pre = my_stack.top();
    while (cur!=pre and last != pre)
    {
        cout<<"pre: "<<pre->val<<"  cur: "<<cur->val<<"  last: "<<last->val<<endl;
        // ListNode * temp = cur->next;
        cur->next = pre;
        pre->next = last;
        my_stack.pop();
        pre = my_stack.top();
        cur = last;
        last = cur->next;

    }
    pre->next = nullptr;
}
