/*
@File  :1020_dfs.cpp
@Author:dfc
@Date  :2023/3/21  14:59
@Desc  :
*/
#include "vector"
#include "iostream"

using namespace std;

vector<vector<int>> directions= {{-1,0},{1,0},{0,-1},{0,1}};
int flag = 0;
int count = 0;

void dfs(vector<vector<int>>&grid, int x1, int x2, vector<vector<int>>&visited)
{
    visited[x1][x2] = 1;
    count ++;
    if (x1==0 or x1 == grid.size()-1 or x2==0 or x2 == grid[0].size()-1)
        flag=1;
    for (int i = 0; i < 4; ++i) {
        int next_x1 = x1+directions[i][0];
        int next_x2 = x2 + directions[i][1];
        if (next_x1<0 or next_x1>grid.size()-1 or next_x2<0 or next_x2>grid[0].size()-1) continue;
        if (grid[next_x1][next_x2]==1 and visited[next_x1][next_x2]==0)
            dfs(grid,next_x1,next_x2,visited);
    }
}
int numEnclaves(vector<vector<int>>& grid)
{
    vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0) );
    int result = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j]==1 and visited[i][j]==0)
            {
                flag=0;
                count=0;
                dfs(grid,i,j,visited);
                if (flag==0)
                    result+=count;
            }
        }
    }
    return result;
}


