/*
@File  :1020_dfs_2.cpp
@Author:dfc
@Date  :2023/3/24  15:21
@Desc  :
*/
#include "iostream"
#include "vector"
using namespace std;

int count = 0;
vector<vector<int>>directions = {{-1,0},{1,0},{0,-1},{0,1}};
void dfs(vector<vector<int>>&grid, int x1, int x2) // 从某个点开始 搜索连接的块 并把置为0
{
    grid[x1][x2] = 0;
    count++;
    for (int i = 0; i < 4; ++i) {
        int next_x1 = x1 + directions[i][0];
        int next_x2 = x2 + directions[i][1];
        if (next_x1<0 or next_x1>grid.size()-1 or next_x2<0 or next_x2>grid[0].size()-1) continue;
        if (grid[next_x1][next_x2]==1)
            dfs(grid,next_x1,next_x2);
    }
}


int numEnclaves(vector<vector<int>>& grid)
{
    for (int i = 0; i < grid.size(); ++i) {
        if (grid[i][0]==1) dfs(grid,i,0);
        if (grid[i][grid[0].size()-1]==1 ) dfs(grid,i,grid[0].size()-1);
    }
    for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[0][j]==1) dfs(grid,0,j);
        if (grid[grid.size()-1][j]==1) dfs(grid,grid.size()-1,j);
    }
    int result = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j]==1)
            {
                count=0;
                dfs(grid,i,j);
                result += count;
            }
        }
    }
    return result;
}