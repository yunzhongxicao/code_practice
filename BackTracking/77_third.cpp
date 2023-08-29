/*
@File  :77_third.cpp
@Author:dfc
@Date  :2023/7/15  12:08
@Desc  :
*/
#include "iostream"
#include "vector"

using namespace std;

vector<int> path;
vector<vector<int>> result;

void backtracking(int start,int n, int k)
{
    if (path.size()==k)
    {
        result.push_back(path);
        return;
    }
    for (int i = start; i <=n-k+1 +path.size(); ++i) {
        path.push_back(i);
        backtracking(i+1,n,k);
        path.pop_back();
    }
}

vector<vector<int>> combine(int n, int k)
{
    backtracking(1,n,k);
    return result;
}


