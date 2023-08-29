/*
@File  :200_third.cpp
@Author:dfc
@Date  :2023/7/18  23:37
@Desc  :
*/
#include "iostream"
#include "vector"

using namespace std;

vector<vector<int>> directions{{-1,0},{1,0},{0,-1},{0,1}};

void dfs(int x1, int x2,vector<vector<char>>& grid, vector<vector<int>>& visited)
{
    // if (visited[x1][x2]==1) return;
    int m = grid.size()-1;
    int n = grid[0].size()-1;
    visited[x1][x2] = 1;
    for (int i = 0; i < 4; ++i) {
        int new_x1 = x1+directions[i][0];
        int new_x2 =  x2 + directions[i][1];
        if (new_x1<0 or new_x1>m  or new_x2<0 or new_x2>n   ) continue;
        if (grid[new_x1][new_x2]=='0') continue;
        if (grid[new_x1][new_x2]=='1' and visited[new_x1][new_x2]==1) continue;
        dfs(new_x1,new_x2,grid,visited);
    }
}

int numIslands(vector<vector<char>>& grid)
{
    int m = grid.size()-1;
    int n = grid[0].size()-1;
    vector<vector<int>> visited(m+1,vector<int>(n+1,0));
    int result = 0;
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n ; ++j) {
            if (visited[i][j] == 1 and grid[i][j] =='1') continue;
            if (grid[i][j] =='0' ) continue;
            dfs(i,j,grid,visited);
            result++;
        }
    }
    return result;
}

