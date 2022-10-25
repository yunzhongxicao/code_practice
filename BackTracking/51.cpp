/*
@File  :51.cpp
@Author:dfc
@Date  :2022/10/25  10:21
@Desc  : N�ʺ�
*/

#include "vector"
#include "iostream"
#include "string"

using namespace std;

vector<vector<string>> result;
bool is_valid(int row, int col,const vector<string>& chessboard)
{
    //ͬһ���ж�
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

void backtracking(int n, int row, vector<string> &chessboard) // ����ÿ��Ҫ�������������Ϣ������һ��
                                                                // ��Ϊ��һ��Ҫ�����Ƿ���Ч���ж�
                                                                // ��Ϊresult push�����������������path�൱��������
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
            chessboard[row][i]='.'; // ��������������
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