/*
@File  :offer_35.cpp
@Author:dfc
@Date  :2022/12/26  13:27
@Desc  : 复杂链表的复制
*/
#include "iostream"
#include "unordered_map"
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
/*
Node* copyRandomList(Node* head) // 哈希表的写法 但是自己想的 偏麻烦了
{
    unordered_map<Node*,Node*>my_map;
    if (!head) return nullptr;
    Node *p =head;
    Node *new_node = new Node(0);
    Node * q = new_node;
    while (p)
    {
        Node *tmp;
        if (my_map.find(p)==my_map.end())
        {
            tmp = new Node(p->val);
        }
        else
        {
            tmp = my_map.find(p)->second;
        }
        my_map[p] = tmp;


        if (p->next== nullptr)
            tmp->next== nullptr;
        else
        {
            Node *tmp_next;
            if (my_map.find(p->next)==my_map.end())
                tmp_next = new Node(p->next->val);
            else
                tmp_next = my_map.find(p->next)->second;
            my_map[p->next]=tmp_next;
            tmp->next = tmp_next;
        }

        if (p->random== nullptr)
            tmp->random== nullptr;
        else
        {
            Node *tmp_random;
            if (my_map.find(p->random)==my_map.end())
                tmp_random = new Node(p->random->val);
            else
                tmp_random = my_map.find(p->random)->second;
            my_map[p->random] = tmp_random;
            tmp->random = tmp_random;
        }

        q->next = tmp;
        q= q->next;
        p = p->next;
    }
    return new_node->next;
}*/

/*
Node* copyRandomList(Node* head)  // 哈希表的写法
{
    unordered_map<Node*,Node*>my_map;
    if (!head) return nullptr;
    Node *p =head;
    while (p)
    {
        Node *tmp=new Node(p->val);
        my_map[p] = tmp;
        p = p->next;
    }
    my_map[nullptr] = nullptr; // 其实不加这句话也不会报错 因为后面[]会自动创建 并赋初值为nullptr
    p = head;
    while (p)
    {
        my_map[p]->next = my_map[p->next];
        my_map[p]->random = my_map[p->random];
        p = p->next;
    }
    return my_map[head];
}*/

Node* copyRandomList(Node* head)
{
    if (!head) return nullptr;

    Node *p=head;
    while (p != nullptr)
    {
        Node* tmp = new Node(p->val);
        tmp->next = p->next;
        p->next = tmp;
        p= tmp->next;
    }
    p = head;
    while (p)
    {
        if (p->random)
            p->next->random = p->random->next;
        else
            p->next->random = nullptr;
        p = p->next->next;
    }
    p = head;
    Node *first = head->next;
    while (p)
    {
        if (p->next->next)
        {
            Node *tmp = p->next->next;
            p->next->next = p->next->next->next;
            p->next = tmp;
            p=p->next;
        }
        else
        {
            p->next= nullptr;
            p=p->next;
        }
    }
    return first;
}
