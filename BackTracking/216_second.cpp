/*
@File  :216_second.cpp
@Author:dfc
@Date  :2023/3/5  17:13
@Desc  : 组合总和3
*/
#include "iostream"
#include "vector"
using namespace std;

vector<int> path;
int sum = 0;
vector<vector<int>> result;

void backtracking(int start, int k,int n)
{
    if (path.size()==k)
    {
        if (sum==n)
            result.push_back(path);
        return;
    }
    if (sum>=n)
        return;
    for (int i = start; i <=9 ; ++i) {
        sum+= i;
        if (sum>n)
        {
            sum-=i;
            break;
        }
        path.push_back(i);
        backtracking(i+1,k,n);
        sum -= i;
        path.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n)
{
    backtracking(1,k,n);
    return result;
}
