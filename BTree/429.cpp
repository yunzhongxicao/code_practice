/*
@File  :429.cpp
@Author:dfc
@Date  :2022/10/5  19:17
@Desc  : N ²æÊ÷µÄ²ãÐò±éÀú
*/

#include "iostream"
#include "vector"
#include "queue"

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

vector<vector<int>> levelOrder(Node* root)
{
    vector<vector<int>> result;
    Node *p;
    queue<Node*> my_queue;

    if (!root) return result;

    my_queue.push(root);

    while (!my_queue.empty())
    {
        int size = my_queue.size();
        vector<int> val;

        for (int i = 0; i < size; ++i) {
            p = my_queue.front();
            my_queue.pop();
            val.push_back(p->val);
            for(auto& child:p->children)
            {
                my_queue.push(child);
            }

        }
        result.push_back(val);
    }
    return result;

}