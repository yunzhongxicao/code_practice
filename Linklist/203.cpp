/*
@File  :203.cpp
@Author:dfc
@Date  :2022/8/26  10:03
@Desc  : 移除链表元素
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
    while (cur!=NULL and cur->next != NULL)  // 这里是因为cur经过前面删除后有可能已经空了
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

ListNode* removeElements_2(ListNode* head, int val)  // 设置虚拟头节点
{
    ListNode* dummy_head =new  ListNode(0);
    dummy_head->next = head;
    ListNode* cur = dummy_head;
    while (cur->next != NULL)  //因为这里已经确认了cur是有值的，每次判断cur的下一个
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