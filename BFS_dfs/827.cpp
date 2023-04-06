/*
@File  :827.cpp
@Author:dfc
@Date  :2023/4/5  23:38
@Desc  :
*/
#include "iostream"
#include "vector"
#include "unordered_map"
#include "unordered_set"

using namespace std;
vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
int area = 0;

void dfs(vector<vector<int>>&grid, int x1, int  x2, int  index)
{
    area++;
    grid[x1][x2] = index;
    for (int i = 0; i < 4; ++i) {
        int next_x1 = x1+  directions[i][0];
        int next_x2 = x2 + directions[i][1];
        if (next_x1<0 or next_x1>grid.size()-1 or next_x2<0 or next_x2>grid[0].size()-1) continue;
        if (grid[next_x1][next_x2]==1)
            dfs(grid,next_x1,next_x2,index);
    }
}

int largestIsland(vector<vector<int>>& grid)
{
    int index = 2;
    unordered_map<int,int>my_map;
    my_map[0]  = 0; // 方便后面计算
    int result = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j]==1)
            {
                area=0;
                dfs(grid,i,j,index);
                my_map[index] = area;
                index++;
                result = max(result,area);
            }
        }
    }

    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j]==0)
            {
                unordered_map<int,int> map_temp;
                for (int k = 0; k < 4; ++k) {
                    int next_x1 = i+  directions[k][0];
                    int next_x2 = j + directions[k][1];
                    if (next_x1<0 or next_x1>grid.size()-1 or next_x2<0 or next_x2>grid[0].size()-1) continue;
                    map_temp[grid[next_x1][next_x2]]++;
                }
                int result_temp = 0;
                for(auto &iter:map_temp)
                {
                    result_temp += my_map[iter.first];
                }
                result = max(result, result_temp+1);
            }
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> grid = {{1,0},{0,1}};
    cout<<largestIsland(grid);
}
