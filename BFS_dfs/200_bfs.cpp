/*
@File  :200_bfs.cpp
@Author:dfc
@Date  :2023/3/21  13:34
@Desc  :
*/
#include "vector"
#include "vector"
#include "queue"
using namespace std;

vector<vector<int>>directions = {{-1,0},{1,0},{0,-1},{0,1}};
int result =0;
void bfs(vector<vector<char>> &grid, int x1,int x2, vector<vector<int>>&visited)
{
    queue<pair<int,int>> my_queue;
    pair<int,int>pair_0(x1,x2);
    visited[x1][x2]=1;
    my_queue.push(pair_0);
    while (!my_queue.empty())
    {
        pair<int,int> temp = my_queue.front();
        my_queue.pop();
        for (int i = 0; i < 4; ++i) {
            int next_x1 = temp.first + directions[i][0];
            int next_x2 = temp.second + directions[i][1];
            if (next_x1<0 or next_x1>grid.size()-1 or next_x2<0 or next_x2>grid[0].size()-1 ) // 越界 直接跳过
                continue;
            if (grid[next_x1][next_x2]=='1' and visited[next_x1][next_x2]==0) {
                my_queue.push(pair<int, int>(next_x1, next_x2));
                visited[next_x1][next_x2] = 1;  // 加入队列就标记
            }
        }
    }
}

int numIslands(vector<vector<char>>& grid)
{
    vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j]=='1' and visited[i][j]==0)
            {
                result++;
                bfs(grid,i,j,visited);
            }
        }
    }
    return result;
}


