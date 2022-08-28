/*
@File  :206.cpp
@Author:dfc
@Date  :2022/8/26  20:32
@Desc  :·­×ªÁ´±í
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

ListNode* reverseList(ListNode* head);

int main()
{

}

ListNode* reverseList(ListNode* head)
{
    ListNode* pre = NULL;
    ListNode* cur = head;
    ListNode* tmp ;
    while (cur!= NULL)
    {
        tmp = cur->next;
        cur->next= pre;
        pre = cur;
        cur = tmp;

    }
    return pre;
}