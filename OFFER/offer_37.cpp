/*
@File  :offer_37.cpp
@Author:dfc
@Date  :2022/12/27  11:38
@Desc  : 序列化二叉树
*/
#include "iostream"
#include "vector"
#include "queue"
#include "stack"
#include "sstream"
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<string> split(const string &s, char delim);

string serialize(TreeNode* root)
{
    string result;
    if (!root) return result;
    queue<TreeNode*> my_queue;
    my_queue.push(root);
    TreeNode *p;
    while (!my_queue.empty())
    {
        p = my_queue.front();
        my_queue.pop();
        if (p)
        {
            result.append(to_string(p->val)+',' );
            my_queue.push(p->left);
            my_queue.push(p->right);
        }
        else result.append("null,");
    }
    result.pop_back(); // 最后一个逗号
    return result;
}


TreeNode* deserialize(string data)
{
    if (data.empty()) return nullptr;
    vector<string> node_vec = split(data,',');
    TreeNode *head = new TreeNode(stoi(node_vec[0]));
    int index=1;
    queue<TreeNode*>my_queue;
    my_queue.push(head);
    TreeNode *p;
    string left_node_val,right_node_val;
    while (!my_queue.empty())
    {
        p = my_queue.front();
        my_queue.pop();
        left_node_val = node_vec[index];
        right_node_val = node_vec[index+1];
        index+=2;
        if (left_node_val!="null")
        {
            TreeNode *left_node = new TreeNode(stoi(left_node_val));
            p->left = left_node;
            my_queue.push(left_node);
        }
        if (right_node_val!="null")
        {
            TreeNode *right_node = new TreeNode(stoi(right_node_val));
            p->right = right_node;
            my_queue.push(right_node);
        }
    }
    return head;
}

vector<string> split(const string &s, char delim)
{
    vector<string> result;
    stringstream ss (s);
    string item;
    while (getline(ss,item,delim))
    {
        result.push_back(item);
    }
    return result;
}

int main()
{
    string str = "adsf+qwer+poui+fdgh";
    vector<string> v = split (str, '+');

    for (auto i : v) cout << i << endl;

    return 0;
}