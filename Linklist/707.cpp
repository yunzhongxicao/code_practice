/*
@File  :707.cpp
@Author:dfc
@Date  :2022/8/26  11:23
@Desc  : 设计链表
*/
#include "iostream"
#include "vector"
using namespace std;

class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int val):val(val), next(nullptr){}
    };
    MyLinkedList() {
        _dummyHead =new  ListNode(0);
        _size = 0;
    }

    int get(int index) {
        if (index>_size-1 or  index<0)
            return -1;

        ListNode* cur = _dummyHead->next;
        while (index>0)
        {
            cur = cur->next;
            index--;
        }
        cout<<"get:  "<<cur->val<<endl;
        return  cur->val;
    }

    void addAtHead(int val) {
        ListNode* tmp = _dummyHead->next;
        ListNode* head = new ListNode(val);
        _dummyHead->next = head;
        head->next = tmp;
        _size++;
    }

    void addAtTail(int val) {
        ListNode* new_node = new ListNode(val);
        ListNode* cur = _dummyHead;
        while (cur->next!=NULL)
        {
            cur = cur->next;
        }
        cur->next = new_node;
        new_node->next = NULL;
        _size++;
    }

    void addAtIndex(int index, int val) {
        if (index>_size)
            return;

        ListNode* new_node = new ListNode(val);
        ListNode* cur = _dummyHead;
        if (index<0)
            index =0;
        if (index==0)
        {
            addAtHead(val);
            return;
        }
        while (index>0)
        {
            cur = cur->next;
            index--;
        }
        ListNode* tmp = cur->next;
        cur->next = new_node;
        new_node->next = tmp;
        _size++;
    }

    void deleteAtIndex(int index) {
        if (index>_size-1 or  index<0)
            return;
        ListNode* cur = _dummyHead;
        while (index>0)
        {
            cur = cur->next;
            index--;
        }
        ListNode* tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;
        _size--;
    }
    void printLinklist()
    {
        ListNode* cur = _dummyHead;
        while (cur->next != NULL)
        {
            cout<<cur->next->val<<"  ";
            cur = cur ->next;
        }
        cout<<endl;
    }
private:
    int _size;
    ListNode* _dummyHead;
};

int  main(){
    MyLinkedList linkedList;
    linkedList.addAtHead(1);
    linkedList.printLinklist();
    linkedList.addAtTail(3);
    linkedList.printLinklist();
    linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
    linkedList.printLinklist();

    linkedList.get(1);            //返回2
    linkedList.deleteAtIndex(1);  //现在链表是1-> 3
    linkedList.printLinklist();

    linkedList.get(1);            //返回3


}