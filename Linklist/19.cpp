/*
@File  :19.cpp
@Author:dfc
@Date  :2022/8/28  10:38
@Desc  : ɾ����������n���ڵ�
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

// ���ֵ����Ķ�����������ָ������������������ȷ�Ϊ���Σ���һ������n����Ȼ������һ����
// ��ô�ڶ���ʣ�µľ�Ӧ�ú͵�һ�����ߵ�n����һ����

ListNode* removeNthFromEnd(ListNode* head, int n);

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode* dummy_head = new ListNode(0);
    dummy_head->next = head;
    ListNode* fast_node = dummy_head;
    ListNode* slow_node = dummy_head;
    int count = 0;
    while (count<n)
    {
        fast_node = fast_node->next;
        count++;
    }
    // ��ʱfast_node����n��
    while (fast_node->next!=NULL)
    {
        fast_node = fast_node->next;
        slow_node = slow_node->next;
    }
    ListNode* tmp = slow_node->next;
    slow_node->next = tmp->next;
    delete  tmp;

    return dummy_head->next;
}

