/*
@File  :695_bfs.cpp
@Author:dfc
@Date  :2023/3/21  14:29
@Desc  :
*/
#include "iostream"
#include "vector"
#include "queue"

using namespace std;
int count=0;
vector<vector<int>>directions= {{-1,0},{1,0},{0,-1},{0,1}};

void bfs(vector<vector<int>> &grid, int x1, int x2, vector<vector<int>> &visited)
{
    visited[x1][x2] = 1;
    count++;
    pair<int,int> my_pair0= {x1,x2};
    queue<pair<int,int>> my_queue;
    my_queue.push(my_pair0);
    while (!my_queue.empty())
    {
        pair<int,int> temp = my_queue.front();
        my_queue.pop();
        for (int i = 0; i < 4; ++i) {
            int next_x1 = temp.first+directions[i][0];
            int next_x2 = temp.second +  directions[i][1];
            if (next_x1<0 or next_x1>grid.size()-1 or next_x2<0 or next_x2>grid[0].size()-1) continue;
            if (grid[next_x1][next_x2]==1 and visited[next_x1][next_x2]==0) // 每次加入的时候就处理了
            {
                my_queue.push(pair<int,int>(next_x1,next_x2));
                visited[next_x1][next_x2] = 1;
                count++;
            }
        }
    }
}

int maxAreaOfIsland(vector<vector<int>>& grid)
{
    vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
    int result = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j]==1 and visited[i][j]==0)
            {
                count= 0;
                bfs(grid,i,j,visited);
                result = max(result,count);
            }
        }
    }
    return result;
}