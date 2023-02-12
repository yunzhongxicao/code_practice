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
    while (pre->next and pre->next->next) // ����������ͷ�ڵ�� ��ֻ�к����һ���ڵ� �ͺ��治�ӽڵ����� ���������
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
