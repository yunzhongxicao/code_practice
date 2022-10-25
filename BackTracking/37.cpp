/*
@File  :37.cpp
@Author:dfc
@Date  :2022/10/25  12:16
@Desc  : 解数独
*/
#include "iostream"
#include "vector"
#include "string"

using namespace std;

bool is_valid(int row, int col, char k, const vector<vector<char>> & board)
{
    for (int i = 0; i < 9; ++i) {
        if (board[row][i]==k) return false;
    }
    for (int i = 0; i < 9; ++i) {
        if (board[i][col]==k) return false;
    }
    int col_num = col / 3; // 纵向第几个小宫格
    int row_num = row / 3;
    for (int i = row_num*3; i <=row_num*3+2 ; ++i) {
        for (int j = col_num*3 ; j <=col_num*3+2 ; ++j) {
            if (board[i][j]==k) return false;
        }
    }
    return true;
}

bool backtracking(int row, int col, vector<vector<char>>& board)
{
    for (int i = row; i < 9 ; ++i) {
        for (int j = col; j < 9; ++j) {
            if (board[i][j]!='.')continue;
            for (char k = '1'; k <='9' ; ++k) {
                if (is_valid(i,j,k,board))
                {
                    board[i][j]=k;
                    bool flag;
                    if (j<8)
                        flag = backtracking(row,j+1,board);
                    else
                        flag = backtracking(row+1,0,board);
                    if (flag)
                        return true;
                    else board[i][j]='.';
                }
            }
            return false;
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>>& board)
{
    backtracking(0,0,board);
}
