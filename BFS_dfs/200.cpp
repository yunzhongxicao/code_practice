/*
@File  :200.cpp
@Author:dfc
@Date  :2023/3/21  11:29
@Desc  :
*/
#include "iostream"
#include "vector"
using namespace std;

int result=0;

void dfs(vector<vector<char>> &grid,int x1, int x2, vector<vector<int>> &visited)
{
    visited[x1][x2] = 1;
    if (x1+1<=grid.size()-1 and  grid[x1+1][x2]=='1' and visited[x1+1][x2]==0) // 向下搜索
    {
        dfs(grid,x1+1,x2,visited);
    }
    if (x1-1>=0 and  grid[x1-1][x2]=='1' and visited[x1-1][x2]==0) // 向上搜索
    {
        dfs(grid,x1-1,x2,visited);
    }
    if (x2+1<=grid[0].size()-1 and grid[x1][x2+1]=='1' and visited[x1][x2+1]==0 ) // 向右搜索
    {
        dfs(grid,x1,x2+1,visited);
    }
    if (x2-1>=0 and grid[x1][x2-1]=='1' and visited[x1][x2-1]==0 ) // 向左搜索
    {
        dfs(grid,x1,x2-1,visited);
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
                dfs(grid,i,j,visited);
            }
        }
    }
    return result;
}