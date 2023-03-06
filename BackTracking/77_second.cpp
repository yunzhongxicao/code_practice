/*
@File  :77_second.cpp
@Author:dfc
@Date  :2023/3/5  16:56
@Desc  : ×éºÏ
*/
#include "iostream"
#include "vector"
using namespace std;

vector<int> path;
vector<vector<int>> result;

void backtracking(int start, int k ,int n )
{
    if (path.size()==k  )
    {
        result.push_back(path);
        return;
    }
    for (int i = start; i <=n-k+path.size()+1 ; ++i) {
        path.push_back(i);
        backtracking(i+1,k,n);
        path.pop_back();
    }
}


vector<vector<int>> combine(int n, int k)
{
    backtracking(1,k,n);
    return result;
}

