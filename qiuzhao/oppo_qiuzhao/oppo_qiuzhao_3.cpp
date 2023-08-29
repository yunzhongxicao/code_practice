/*
@File  :oppo_qiuzhao_3.cpp
@Author:dfc
@Date  :2023/8/26  17:38
@Desc  :
*/
#include "iostream"
#include "string"
#include "vector"
using namespace std;

int count = 0;
int result = 0;

string mask = "oppo";

void dfs(vector<vector<int>>& graph, int cur ,int pre,string &s)
{
    // count++;
    if (count==3)
    {
        result++;
        return;
    }

    for(auto next : graph[cur])
    {
        if (next==pre) continue;
        count++;
        if (s[next-1] == mask[count])
            dfs(graph,next,cur,s);
        count--;
    }
}

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<vector<int>> graph(n+1, vector<int>());
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        if (s[i-1]=='o')
        {
            count = 0;
            dfs(graph,i,0,s );
        }
    }
    cout<<result;
}

