/*
@File  :841.cpp
@Author:dfc
@Date  :2023/4/9  11:39
@Desc  :
*/
#include "iostream"
#include "vector"
using namespace std;

void dfs(vector<vector<int>>&rooms, int current_node, vector<int>&visited)
{
    visited[current_node] = 1;
    for (int i = 0; i < rooms[current_node].size(); ++i) {
        int next_room = rooms[current_node][i];
        if (visited[next_room] == 1) continue;
        dfs(rooms,next_room,visited);
    }
}

bool canVisitAllRooms(vector<vector<int>>& rooms)
{
    vector<int> visited(rooms.size(),0);
    dfs(rooms,0,visited);
    for (int i = 0; i < visited.size(); ++i) {
        if (visited[i]==0) return false;
    }
    return true;
}

