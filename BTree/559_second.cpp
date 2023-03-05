/*
@File  :559_second.cpp
@Author:dfc
@Date  :2023/3/4  14:01
@Desc  : N 叉树的最大深度
*/
#include "iostream"
#include "vector"
using namespace std;
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

int maxDepth(Node* root)
{
    if (!root) return 0;
    int result=0;
    for (int i = 0; i < root->children.size(); ++i) {
        int temp= maxDepth(root->children[i]);
        result = max(result,temp);
    }
    return 1+result;
}



