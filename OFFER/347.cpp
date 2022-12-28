/*
@File  :347.cpp
@Author:dfc
@Date  :2022/12/28  16:55
@Desc  : ǰk����ƵԪ��
*/
#include "iostream"
#include "vector"
#include "unordered_map"
#include "queue"

using namespace std;

class mycomparison
{
public:
    bool operator()(const pair<int,int >& lhs, const pair<int,int > & rhs ) //ͨ���� cmp �ࣨ�ṹ�壩���ص� () ��������Զ����������
    {
        return lhs.second>rhs.second;
    }
};

vector<int> topKFrequent(vector<int>& nums, int k)
{
    unordered_map<int ,int>my_map;
    for (int & num : nums) {
        my_map[num]++;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,mycomparison >my_que;
    for(auto &it:my_map)
    {
        my_que.push(it);
        if (my_que.size()>k)
        {
            my_que.pop();
        }
    }
    vector<int> result;
    while (!my_que.empty())
    {
        result.push_back(my_que.top().first);
        my_que.pop();
    }
    return result;
}

