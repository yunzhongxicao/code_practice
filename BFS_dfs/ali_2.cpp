/*
@File  :ali_2.cpp
@Author:dfc
@Date  :2023/4/5  16:34
@Desc  :
*/
#include "iostream"
#include "vector"
using namespace std;
vector<vector<int>> directions ={{-1,0},{1,0},{0,-1},{0,1}};

void dfs(const vector<vector<char>> &board, int x1, int x2, vector<vector<int>>&visited)
{
    visited[x1][x2] = 1;
    for (int i = 0; i < 4; ++i) {
        int next_x1 = x1 + directions[i][0];
        int next_x2  = x2 + directions[i][1];
        if (next_x1<0 or next_x1>board.size()-1 or next_x2<0 or next_x2> board[0].size()-1) continue;
        if (board[next_x1][next_x2]=='R' and visited[next_x1][next_x2]==0)
            dfs(board,next_x1,next_x2,visited);
    }
}

int search_once( const vector<vector<char>>&board)
{
    vector<vector<int>> visited(board.size(),vector<int>(board.size(),0));
    int result = 0;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            if (board[i][j]=='R' and visited[i][j]==0)
            {
                result++;
                dfs(board,i,j,visited);
            }
        }
    }
    return result;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>board(n,vector<char>(m));
    for (int i = 0; i < n; ++i) {
        string temp;
        cin>>temp;
        for (int j = 0; j < m; ++j) {
            board[i][j]=temp[j];
        }
    }
    int normal_result = search_once(board);
    vector<vector<int>> result(n,vector<int>(m));
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            if (board[i][j]=='W') result[i][j] = normal_result;
            else
            {
                board[i][j] = 'W';
                result[i][j] = search_once(board);
                board[i][j] = 'R';
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}

