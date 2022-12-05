/*
@File  :offer_06.cpp
@Author:dfc
@Date  :2022/12/5  10:16
@Desc  : 从尾到头打印链表
*/
#include "vector"
#include "iostream"
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
vector<int> reversePrint(ListNode* head)
{
    ListNode * cur = head;
    int count = 0;
    while (cur != NULL)
    {
        count++;
        cur = cur->next;
    }
    int now_index = 0;
    vector<int> result(count);
    cur = head;
    while (cur != NULL)
    {
        result[count-now_index-1] = cur->val;
        cur = cur->next;
        now_index++;
    }
    return result;

}


