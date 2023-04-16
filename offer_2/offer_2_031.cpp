/*
@File  :offer_2_031.cpp
@Author:dfc
@Date  :2023/4/16  15:12
@Desc  :
*/
#include "iostream"
#include "unordered_map"
#include "vector"

using namespace std;

struct DLinkList{
    int key;
    DLinkList * pre;
    DLinkList * next;
    DLinkList(int x):key(x),pre(nullptr),next(nullptr){};
};

class LRUCache {
public:
    int count = 0;
    DLinkList *dummy_head = new DLinkList(0);
    DLinkList *dummy_tail = new DLinkList(0);
    int _capacity;
    unordered_map<int ,int> my_map;
    LRUCache(int capacity) {
        _capacity = capacity;
        dummy_head->next =dummy_tail;
        dummy_tail->pre = dummy_head;
    }

    int get(int key) {
        if (my_map.find(key) == my_map.end()) return -1;
        move_to_head(key);
        return my_map[key];
    }

    void put(int key, int value) {
        if (my_map.find(key) != my_map.end())
        {
            my_map[key] = value;
            move_to_head(key);
        }
        else
        {
            if (count<_capacity)
            {
                my_map[key] = value;
                add_at_head(key);
                count++;
            }
            else
            {
                DLinkList *temp = dummy_tail->pre;
                my_map.erase(temp->key);
                temp->pre->next = temp->next;
                dummy_tail->pre = temp->pre;
                delete temp;

                my_map[key] = value;
                add_at_head(key);
            }
        }
    }
    void move_to_head(int key)
    {
        DLinkList *cur = dummy_head->next;
        while (cur->key != key)
        {
            cur = cur->next;
        }
        cur->pre->next = cur->next;
        cur->next->pre = cur->pre;
        delete cur;
        add_at_head(key);
    }
    void add_at_head(int key)
    {
        DLinkList *temp = new DLinkList(key);
        temp->next = dummy_head->next;
        dummy_head->next->pre = temp;
        dummy_head->next = temp;
        temp->pre = dummy_head;
    }
};

