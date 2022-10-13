/*
@File  :513.cpp
@Author:dfc
@Date  :2022/10/10  10:38
@Desc  :�������½ǵ�ֵ
*/

#include "iostream"
#include "stack"
#include "vector"
#include "queue"
#include <numeric>

using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
public:
    TreeNode(){val=0;left=NULL;right=NULL;};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};


/* ���Ƿǵݹ��д��
int findBottomLeftValue(TreeNode* root)
{
    vector<vector<int>> result;
    queue<TreeNode*> my_queue;
    TreeNode *p;

    if (!root) return 0;

    my_queue.push(root);
    while (!my_queue.empty())
    {
        int size = my_queue.size();
        vector<int> val;

        for (int i = 0; i < size; ++i) {
            p = my_queue.front();
            my_queue.pop();
            val.push_back(p->val);
            if (p->left) my_queue.push(p->left);
            if (p->right) my_queue.push(p->right);
        }
        result.push_back(val);
    }
    return result.back()[0];

}*/

void get_max_depth(TreeNode* p, int depth, int &max_depth, TreeNode &max_node);
int findBottomLeftValue(TreeNode* root)
{
    TreeNode result_node;
    int max_depth = 0;
    int result;
    if (!root) return result;

    get_max_depth(root,1,max_depth,result_node);
    return result_node.val;
}


void get_max_depth(TreeNode* p, int depth, int &max_depth, TreeNode &max_node)  // ע�� �����max_node������ָ�봫��
                                                                                // ��Ϊָ�봫�ݱ�������ֵ���� �Ǹ��� �����������޸�ָ���ֵ�޷�Ӱ�쵽ʵ��
                                                                                // ����������Ҫ�ѽڵ㴫�ݳ��� ���Բ�����ָ�봫��
                                                                                // �ǾͿ��������ô��� ����ȥ�ľ���һ��TreeNode�� �ı�����Ȼ�󽫱������¸�ֵ
                                                                                // �ٴ����һ�� ���ô��ݵĲ�����ʵ����һ���������������ڼ��Ѱַ ����ʵ�ֶ��β��޸�Ӱ�쵽ʵ��
{
    if (depth>max_depth)
    {
        max_depth = depth;
        max_node = *p;
    }
    if (p->left==NULL and p->right ==NULL) return;

    if (p->left)
    {
        depth++;
        get_max_depth(p->left,depth,max_depth,max_node);
        depth--;
    }
    if (p->right)
    {
        depth++;
        get_max_depth(p->right,depth,max_depth,max_node);
        depth--;
    }
}
