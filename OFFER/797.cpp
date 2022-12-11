/*
@File  :797.cpp
@Author:dfc
@Date  :2022/12/11  11:11
@Desc  : 所有可能的路径
*/
#include "iostream"
#include "vector"
using namespace std;

vector<int> path;
vector<vector<int>> result;
void bfs(int num, int n,vector<vector<int>>& graph);
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
{
    path.push_back(0);
    bfs(0,graph.size(),graph);
    return result;
}

void bfs(int num, int n,vector<vector<int>>& graph)
{
    if (num==n-1)
    {
        result.push_back(path);
        return;
    }
    for (int i = 0; i < graph[num].size(); ++i) {
        path.push_back(graph[num][i]);
        bfs(graph[num][i],n,graph);
        path.pop_back();
    }
}

