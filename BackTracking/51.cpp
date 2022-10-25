/*
@File  :51.cpp
@Author:dfc
@Date  :2022/10/25  10:21
@Desc  : N皇后
*/

#include "vector"
#include "iostream"
#include "string"

using namespace std;

vector<vector<string>> result;
bool is_valid(int row, int col,const vector<string>& chessboard)
{
    //同一列判断
    for (int i = 0; i <=row-1  ; ++i) {
        if (chessboard[i][col]=='Q') return false;
    }
    for (int i = row-1,j=col-1; i>=0 and j>=0; i--,j--) {
        if (chessboard[i][j]=='Q') return false;
    }
    for (int i = row-1,j=col+1; i>=0 and j<=chessboard.size()-1 ; i--,j++) {
        if (chessboard[i][j]=='Q') return false;
    }
    return true;
}

void backtracking(int n, int row, vector<string> &chessboard) // 这里每次要把上面的棋盘信息传到下一层
                                                                // 因为下一层要进行是否有效的判断
                                                                // 因为result push的是整个棋盘嘛，所以path相当于棋盘了
{
    if (row==n)
    {
        result.push_back(chessboard);
        return;
    }
    for (int i = 0; i <n ; ++i) {
        if (is_valid(row,i,chessboard))
        {
            chessboard[row][i]='Q';
            backtracking(n,row+1,chessboard);
            chessboard[row][i]='.'; // 回溯体现在这里
        }
    }

}

vector<vector<string>> solveNQueens(int n)
{
    string s(n,'.');
    vector<string> chessboard(n,s);
    backtracking(n,0,chessboard);
    return result;
}

int main()
{
    solveNQueens(4);
    for(const auto& i:result)
    {
        for(const auto& j:i)
        {
            cout<<j<<"   ";
        }
        cout<<endl;
    }
}