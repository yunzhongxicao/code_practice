/*
@File  :707_second.cpp
@Author:dfc
@Date  :2023/2/11  15:19
@Desc  : 涉及链表
*/
#include "iostream"
using namespace std;


class MyLinkedList {
public:
    struct ListNode{
        int val;
        ListNode *next;
        ListNode(int x):val(x),next(nullptr){};
    };
    ListNode *first_node = new ListNode(-1);
    int node_length = 0;
    MyLinkedList() {

    }

    int get(int index) {
        if (index>node_length-1) return -1;
        int count = 0;
        ListNode  *p = first_node->next;
        while (count<index)
        {
            p = p->next;
            count++;
        }
        return p->val;
    }

    void addAtHead(int val) {
        ListNode *temp = new ListNode(val);
        temp->next = first_node->next;
        first_node->next = temp;
        node_length++;
    }

    void addAtTail(int val) {
        addAtIndex(node_length,val);
    }

    void addAtIndex(int index, int val) {
        if (index>node_length) return;
        if (index<0)
        {
            addAtHead(val);
            return;
        }
        int count =0 ;
        ListNode *p = first_node; // 找到被插入那个节点index前面的那个
        while (count<index)
        {
            p = p->next;
            count++;
        }
        ListNode *temp = new ListNode(val);
        temp->next = p->next;
        p->next = temp;
        node_length++;
   }

    void deleteAtIndex(int index) {
        if (index<0 or index>node_length-1) return;
        int count =0;
        ListNode *p = first_node;
        while (count<index)
        {
            count++;
            p = p->next;
        }
        ListNode *temp =  p->next;
        p->next = temp->next;
        delete temp;
        node_length--;
    }
};

