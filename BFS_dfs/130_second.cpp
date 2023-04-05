/*
@File  :130_second.cpp
@Author:dfc
@Date  :2023/4/5  16:12
@Desc  :
*/
#include "iostream"
#include "vector"
using namespace std;

vector<vector<int>>directions = {{-1,0},{1,0},{0,-1},{0,1}};

void dfs(vector<vector<char>>&board,int x1, int x2)
{
    board[x1][x2] = 'a';
    for (int i = 0; i < 4; ++i) {
        int next_x1 = x1 + directions[i][0];
        int next_x2 = x2 + directions[i][1];
        if (next_x1<0 or next_x1>board.size()-1 or next_x2<0 or next_x2>board[0].size()-1) continue;
        if (board[next_x1][next_x2]=='O')
            dfs(board,next_x1,next_x2);
    }
}

void solve(vector<vector<char>>& board)
{
    for (int i = 0; i < board.size(); ++i) {
        if (board[i][0]=='O') dfs(board,i,0);
        if (board[i][board[0].size()-1]=='O') dfs(board,i,board[0].size()-1);
    }
    for (int j = 0; j < board[0].size(); ++j) {
        if (board[0][j]=='O') dfs(board,0,j);
        if (board[board.size()-1][j]=='O') dfs(board,board.size()-1,j);
    }
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            if (board[i][j]=='O') board[i][j] = 'X';
            else if (board[i][j]=='a') board[i][j]='O';
        }
    }
}

