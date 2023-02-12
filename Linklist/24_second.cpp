/*
@File  :24_second.cpp
@Author:dfc
@Date  :2023/2/12  12:23
@Desc  :
*/
#include "iostream"
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(nullptr){};
};

ListNode* swapPairs(ListNode* head)
{
    ListNode *first_node = new ListNode(0);
    first_node->next = head;
    ListNode  *pre = first_node;
    ListNode *cur;

    ListNode *last;
    while (pre->next and pre->next->next) // 设置了虚拟头节点后 就只有后面接一个节点 和后面不接节点两种 情况跳出来
    {
        cur = pre->next;
        last = cur->next;

        pre->next= last;
        cur->next = last->next;
        last->next = cur;

        pre = cur;
    }
    return first_node->next;
}
