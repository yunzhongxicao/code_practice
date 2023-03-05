/*
@File  :429_second.cpp
@Author:dfc
@Date  :2023/3/2  13:30
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
    queue<Node *> my_queue;
    if (!root) return result;
    my_queue.push(root);
    while (!my_queue.empty())
    {
        int size =my_queue.size();
        vector<int> path;
        for (int i = 0; i < size; ++i) {
            Node *temp = my_queue.front();
            my_queue.pop();
            path.push_back(temp->val);
            for (int j = 0; j < temp->children.size(); ++j) {
                if (temp->children[j]) my_queue.push(temp->children[j]);
            }
        }
        result.push_back(path);
    }
    return result;
}

