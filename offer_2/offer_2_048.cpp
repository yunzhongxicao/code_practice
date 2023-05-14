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
            TreeNode *temp = my_queue.front();
            my_queue.pop();
            if (!temp)   // ���л���ʱ���ָ����Ҫ���ȥ�ĵ�
            {
                result += "N,";
            }
            else
            {
                result += to_string(temp->val);
                result += ",";
                my_queue.push(temp->left);
                my_queue.push(temp->right);
            }
        }
        return result;  // ��β����һ������
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vec_s;
        if (data.empty()) return nullptr;
        int start =0;
        int end=0;
        while (start<=data.size()-1)
        {
            end = start;
            while (data[end]!=',')
                end++;
            vec_s.push_back(data.substr(start,end-start));
            start = end+1;
        }
        queue<TreeNode *> my_queue;
        TreeNode *root = new TreeNode(stoi(vec_s[0]));
        my_queue.push(root);
        int index = 0;
        while (!my_queue.empty())
        {
            TreeNode *temp = my_queue.front();
            my_queue.pop();   // �����л���ʱ��ֻ��ǿ�ָ�뼴��

            index++;  // ͨ��index���ַ����ϻ�������ȡ��Ӧ��������
            if (vec_s[index] != "N")
            {
                TreeNode *left_node = new TreeNode(stoi(vec_s[index]));
                temp->left = left_node;
                my_queue.push(left_node);
            }
            index++;
            if (vec_s[index] !="N")
            {
                TreeNode *right_node = new TreeNode(stoi(vec_s[index]));
                temp->right = right_node;
                my_queue.push(right_node);
            }
        }
        return root;
    }
};