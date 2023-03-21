/*
@File  :797.cpp
@Author:dfc
@Date  :2023/3/21  10:51
@Desc  :
*/
#include "iostream"
#include "vector"
using namespace std;

vector<int>path;
vector<vector<int>>result;

void dfs(vector<vector<int>>&graph, int start) // ��ʾ��start�ڵ㿪ʼ����ֹ�ڵ������
{
    path.push_back(start); // ÿһ��һ�����Ͱ��Լ��ӽ�ȥ
    if (start== graph.size()-1)
    {
        result.push_back(path);
        return;
    }
    for (int i = 0; i < graph[start].size(); ++i) { // Ȼ����������ӽڵ�
        dfs(graph,graph[start][i]); // ��һ�����ʼ�ڵ���������ӽڵ�
        path.pop_back();
    }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
{
    dfs(graph,0);
    return result;
}