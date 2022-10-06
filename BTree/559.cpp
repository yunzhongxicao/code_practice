/*
@File  :559.cpp
@Author:dfc
@Date  :2022/10/6  20:36
@Desc  :N叉树的最大深度
*/
#include "iostream"
#include "stack"
#include "vector"
#include "queue"
#include "algorithm"
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

/*
递归写法
int maxDepth(Node* root)
{
    if (!root) return 0;

    int depth = 0;  // 递归的话就不要用vector这种了 很容易报错
    int size = root->children.size();

    for (int i = 0; i < size; ++i) {
        Node *child = root->children[i];
        depth = max(depth,maxDepth(child));
    }
    return 1+ depth;

}*/

int maxDepth(Node* root)
{
    queue<Node*> my_queue;
    Node *p;

    if (!root) return 0;

    my_queue.push(root);
    int depth = 0;
    while (!my_queue.empty())
    {
        int size = my_queue.size();
        depth++;

        for (int i = 0; i < size; ++i) {
            p = my_queue.front();
            my_queue.pop();
            for (int j = 0; j < p->children.size(); ++j) {
                if (p->children[j])
                {
                    my_queue.push(p->children[j]);
                }
            }
        }
    }
    return depth;
}
