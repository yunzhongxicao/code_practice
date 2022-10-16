/*
@File  :501.cpp
@Author:dfc
@Date  :2022/10/16  15:50
@Desc  : ����������������
*/
#include "iostream"
#include "stack"
#include "vector"
#include "queue"
#include "algorithm"
#include "map"
#include "unordered_map"

using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
public:
    TreeNode(){val=0;left=NULL;right=NULL;};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

/* ������ͨ��������д��
vector<int> findMode(TreeNode* root);
void traverse(TreeNode *p,unordered_map<int,int> &my_map);
bool static cmp (const pair<int, int>& a, const pair<int, int>& b);

void traverse(TreeNode *p,unordered_map<int,int> &my_map)
{
    if (!p) return;
    traverse(p->left,my_map);
    my_map[p->val]++;
    traverse(p->right,my_map);
}

vector<int> findMode(TreeNode* root)
{
    vector<int> result;
    if (!root) return result;

    unordered_map<int,int> my_map;

    traverse(root, my_map );

    // ע�����������vector��ʼ���ķ�ʽ
    vector<pair<int,int>> map_vector(my_map.begin(),my_map.end());

    // ���������д��ֵ�ü���
    sort(map_vector.begin(),map_vector.end(), cmp);

    for (int i = 0; i < map_vector.size(); ++i) {
        if (map_vector[i].second!=map_vector[0].second)
            break;
        else
            result.push_back(map_vector[i].first);
    }
    return result;
}


bool static cmp (const pair<int, int>& a, const pair<int, int>& b)
{
    return a.second>b.second;
}*/


/*
// �����������ĵݹ�
int max_count=0,num=0;
TreeNode *last_node= nullptr;
void traverse(TreeNode *p, vector<int> &result);
vector<int> findMode(TreeNode* root)
{
    vector<int> result;
    if (!root) return result;

    traverse(root,result);
    return result;
}

void traverse(TreeNode *p, vector<int> &result)
{
    if (!p) return;
    traverse(p->left,result);

    if (last_node== nullptr)
    {
        num++;
    }
    else if (last_node and p->val == last_node->val)
    {
        num++;
    }
    else if (last_node and p->val != last_node->val)
    {
        // ע�� ���������if�жϲ��ܷŵ������� ��Ϊ��������һ��Ԫ�صĻ���������û��Ԫ���ˣ���û����Ԫ�طŽ�ȥ
        num=1;
    }
    if (max_count< num)
    {
        result.clear();
        result.push_back(p->val);
        max_count=num;
    }
    else if (max_count == num)
    {
        result.push_back(p->val);
    }
    last_node=p;

    traverse(p->right,result);
}
*/


vector<int> findMode(TreeNode* root)
{
    stack<TreeNode *>s1;
    stack<int> s2;
    TreeNode *p,*last_node= nullptr;
    int num =0;
    int max_count=0;

    vector<int> result;

    if (!root) return result;

    s1.push(root);
    s2.push(0);
    while (!s1.empty())
    {
        p = s1.top();
        int flag = s2.top();
        if (flag==0)
        {
            s2.top()=1;
            if (p->left)
            {
                s1.push(p->left);
                s2.push(0);
            }
        }
        else if (flag==1)
        {
            s1.pop();
            s2.pop();

            if (last_node== nullptr)
            {
                num++;
            }
            else if (last_node and p->val == last_node->val)
            {
                num++;
            }
            else if (last_node and p->val != last_node->val)
            {
                // ע�� ���������if�жϲ��ܷŵ������� ��Ϊ��������һ��Ԫ�صĻ���������û��Ԫ���ˣ���û����Ԫ�طŽ�ȥ
                num=1;
            }
            if (max_count< num)
            {
                result.clear();
                result.push_back(p->val);
                max_count=num;
            }
            else if (max_count == num)
            {
                result.push_back(p->val);
            }
            last_node=p;


            if (p->right)
            {
                s1.push(p->right);
                s2.push(0);
            }
        }
    }
    return result;
}