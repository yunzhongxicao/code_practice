/*
@File  :lingxi_4.cpp
@Author:dfc
@Date  :2023/8/27  20:11
@Desc  :
*/
#include "vector"
#include "iostream"

using namespace std;

vector<vector<int>> directions{{-1,0},{1,0}, {0,1}};

long  long  path= 0 ;

long  long  result  = INT32_MIN;
void dfs(int x1, int x2,vector<vector<long  long >>& grid, vector<vector<int>>& visited)
{
    int m = grid.size()-1;
    int n = grid[0].size()-1;
    if (x1== m and x2 == n)
    {
        result = max(result, path);
        return;
    }
    for (int i = 0; i < 3; ++i) {
        int new_x1 = x1+directions[i][0];
        int new_x2 =  x2 + directions[i][1];

        if (x1==0 and i == 0) // 上边缘向上走
        {
            new_x1 = m;
            new_x2 = x2;
            if (visited[new_x1][new_x2] == 1) continue;
            visited[new_x1][new_x2] = 1;
            long  long  tmp  =path;
            path = grid[new_x1][new_x2];
            dfs(new_x1,new_x2, grid, visited    );
            visited[new_x1][new_x2] = 0;
            path = tmp;
        }

        else if (x1== m and i == 1) // 下边缘向下走
        {
            new_x1 = 0;
            new_x2 = x2;
            if (visited[new_x1][new_x2] == 1) continue;
            visited[new_x1][new_x2] = 1;
            long  long  tmp  =path;
            path = grid[new_x1][new_x2];
            dfs(new_x1,new_x2, grid, visited    );
            visited[new_x1][new_x2] = 0;
            path = tmp;
        }
        else
        {
            if (new_x1<0 or new_x1>m  or new_x2<0 or new_x2>n   ) continue;
            if (visited[new_x1][new_x2] == 1) continue;
            visited[new_x1][new_x2] = 1;
            path += grid[new_x1][new_x2];
            dfs(new_x1,new_x2, grid, visited    );
            visited[new_x1][new_x2] = 0;
            path -= grid[new_x1][new_x2];
        }
    }
}

int main()
{
    int m, n;
    cin>>n>>m;
    vector<vector<long  long >> grid(m, vector<long  long >(n,0)    );
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
                cin>>grid[i][j];
        }
    }
    vector<vector<int>> visited(m, vector<int>(n,0));
    visited[0][0] =1;
    path += grid[0][0];
    dfs(0,0,grid,visited);
    cout<<result<<endl;
}

