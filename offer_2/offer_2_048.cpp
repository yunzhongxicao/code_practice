/*
@File  :offer_2_048.cpp
@Author:dfc
@Date  :2023/5/13  9:10
@Desc  :
*/
#include "iostream"
#include "vector"
#include "string"
#include "queue"
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){};
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        if (!root) return result;
        queue<TreeNode *> my_queue;
        my_queue.push(root);
        while (!my_queue.empty())
        {
            
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

    }
};