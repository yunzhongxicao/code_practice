/*
@File  :oppo_1.cpp
@Author:dfc
@Date  :2023/7/9  20:42
@Desc  :
*/
#include <iostream>
#include <vector>
#include "unordered_map"
#include "map"
#include "algorithm"

using namespace std;

map<int, vector<int>> graph;
int  delete_node;
int count_size = 0;
void dfs(int node, vector<int> &visited)
{
    visited[node] = 1;
    for (int child: graph[node]) {
        if (child==delete_node)
            continue;
        if (visited[child] == 1)
            continue;
        count_size++;
        dfs(child,visited);
    }
}

int main()
{
    int num_node;
    cin>>num_node;
    for (int i = 0; i < num_node-1; ++i) {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cin>>delete_node;
    // num_node = 5;
    // graph[1].push_back(2  ); graph[1].push_back(4); graph[1].push_back(5);
    // graph[2].push_back(1); graph[2].push_back(3);
    // graph[3].push_back(2);
    // graph[4].push_back(1);
    // graph[5].push_back(1);
    // delete_node = 1;

    vector<int> result;
    vector<int> visited(graph.size()+1,0);
    for(auto &it : graph)
    {
        int node = it.first;
        if (node==delete_node)
            continue;
        if (visited[node]==1 )
            continue;
        // cout<<"node: "<<node<<endl;
        count_size = 1;
        dfs(node,visited);
        result.push_back(count_size);
    }
    sort(result.begin(),result.end());
    cout<<result.size()<<endl;
    for (int i = 0; i < result.size(); ++i) {
        cout<<result[i]<<" ";
    }
    return 0;
}

