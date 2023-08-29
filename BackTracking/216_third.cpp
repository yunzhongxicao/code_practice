/*
@File  :216_third.cpp
@Author:dfc
@Date  :2023/7/17  22:47
@Desc  :
*/
#include "iostream"
#include "vector"

using namespace std;

vector<int> path;
int sum = 0;
vector<vector<int>> result;

void backtracking(int start, int k, int n)
{
    if (sum>n or path.size()>k)
        return;
    if (sum==n and path.size()<k) return;
    if (sum==n and path.size()==k)
    {
        result.push_back(path);
        return;
    }
    for (int i = start; i <=9-(k-path.size())+1 ; ++i) {
        sum += i;
        path.push_back(i);
        if (sum>n)
        {
            sum-=i;
            path.pop_back();
            return;
        }
        backtracking(i+1,k,n);
        sum -=i;
        path.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n)
{
    backtracking(1,k,n);
    return result;
}

