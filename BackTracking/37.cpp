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
//        for (int j = 0; j < 9; ++j) { //我不太理解为啥col要从 0开始 不应该从当前的下一个开始吗？
        for (int j = col; j < 9; ++j) { //

                if (board[i][j]!='.')
                {
                    if(j==8) col=0;  // 这个语句太关键了 因为除了递归要考虑特殊情况 跳出也要考虑特殊情况，不然会出现如果最后一个有值的话，continue到下一行 又直接从最后一个开始计算了
                    continue;
                }
            for (char k = '1'; k <='9' ; ++k) {
                if (is_valid(i,j,k,board))
                {
                    board[i][j]=k;
                    bool flag;
                    if (j<8)
                        flag = backtracking(i,j+1,board);
                    else
                        flag = backtracking(i+1,0,board);
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

int main()
{
    vector<vector<char>> b = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    solveSudoku(b);

}
