/*
@File  :203.cpp
@Author:dfc
@Date  :2022/8/26  10:03
@Desc  : �Ƴ�����Ԫ��
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
ListNode* removeElements(ListNode* head, int val);
ListNode* removeElements_2(ListNode* head, int val);

int main()
{

}
ListNode* removeElements(ListNode* head, int val)
{
    while (head!=NULL and head->val== val)
    {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
    ListNode* cur = head;
    while (cur!=NULL and cur->next != NULL)  // ��������Ϊcur����ǰ��ɾ�����п����Ѿ�����
    {
        if (cur->next->val == val)
        {
            ListNode* tmp = cur->next;
            cur->next = tmp->next;
            delete tmp;
        } else
        {
            cur = cur->next;
        }
    }
    return head;
}

ListNode* removeElements_2(ListNode* head, int val)  // ��������ͷ�ڵ�
{
    ListNode* dummy_head =new  ListNode(0);
    dummy_head->next = head;
    ListNode* cur = dummy_head;
    while (cur->next != NULL)  //��Ϊ�����Ѿ�ȷ����cur����ֵ�ģ�ÿ���ж�cur����һ��
    {
        if (cur->next->val == val)
        {
            ListNode* tmp = cur->next;
            cur->next = tmp->next;
            delete tmp;
        } else
        {
            cur = cur->next;
        }
    }
    ListNode* tmp = dummy_head;
    head = dummy_head->next;
    delete tmp;
    return head;
}