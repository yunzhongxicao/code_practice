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

void dfs(vector<vector<int>>&graph, int start) // 表示从start节点开始到终止节点的搜索
{
    path.push_back(start); // 每一层一进来就把自己加进去
    if (start== graph.size()-1)
    {
        result.push_back(path);
        return;
    }
    for (int i = 0; i < graph[start].size(); ++i) { // 然后遍历它的子节点
        dfs(graph,graph[start][i]); // 下一层的起始节点就是它的子节点
        path.pop_back();
    }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
{
    dfs(graph,0);
    return result;
}