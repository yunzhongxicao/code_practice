/*
@File  :ali_2_new.cpp
@Author:dfc
@Date  :2023/4/6  10:42
@Desc  :
*/
#include "iostream"
#include "vector"
using namespace std;
vector<vector<int>> directions ={{-1,0},{1,0},{0,-1},{0,1}};

void dfs(vector<vector<int>>& board, int x1, int x2, int index)
{
    board[x1][x2] = index;
    for (int i = 0; i < 4; ++i) {
        int next_x1 = x1 + directions[i][0];
        int next_x2  = x2 + directions[i][1];
        if (next_x1<0 or next_x1>board.size()-1 or next_x2<0 or  next_x2>board[0].size()-1) continue;
        if (board[next_x1][next_x2]==1)
            dfs(board,next_x1,next_x2,index);
    }
}


int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>board(n,vector<int>(m));
    for (int i = 0; i < n; ++i) {
        string temp;
        cin>>temp;
        for (int j = 0; j < m; ++j) {
            if (temp[j]=='W') board[i][j]  = 0; // 白色取0 红色取1
            else board[i][j] = 1;
        }
    }

}

