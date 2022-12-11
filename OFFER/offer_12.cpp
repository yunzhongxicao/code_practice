/*
@File  :offer_12.cpp
@Author:dfc
@Date  :2022/12/11  10:00
@Desc  : 矩阵中的路径
*/
#include "iostream"
#include "vector"

using namespace std;
bool dfs(int row, int col, int k, vector<vector<char>>& board,string &word);
bool exist(vector<vector<char>>& board, string word)
{
    bool result;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            result = dfs(i,j,0,board,word);
            if (result)
                return result;
        }
    }
    return false;
}

bool dfs(int row, int col, int k, vector<vector<char>>& board,string &word)
{
    int m = board.size();
    int n = board[0].size();
    if (row>m-1 or row<0 or col > n-1 or col<0 or board[row][col] != word[k])
        return false;
    if (k==word.size()-1)
        return true;
    char tmp = board[row][col];
    board[row][col] = '.'; // 很重要  不然就会把当前元素给重复考虑了
    bool left = dfs(row,col-1,k+1,board,word);
    bool right = dfs(row,col+1,k+1,board,word);
    bool up = dfs(row-1,col,k+1,board,word);
    bool down = dfs(row+1,col,k+1,board,word);
    board[row][col] = tmp;
    return left or right or up or down;
}

int main()
{

}

