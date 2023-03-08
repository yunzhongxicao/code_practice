/*
@File  :39_second.cpp
@Author:dfc
@Date  :2023/3/7  11:18
@Desc  :
*/
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

vector<int> path;
int sum = 0;
vector<vector<int>> result;

void backtracking(int start, vector<int> & candidates, int target)
{
    if (sum==target)
    {
        result.push_back(path);
        return;
    }
    if (sum>target)
        return;
    for (int i = start; i <candidates.size() ; ++i) {
        sum += candidates[i];
        if (sum>target)
        {
            sum -= candidates[i];
            break;
        }
        path.push_back(candidates[i]);
        backtracking(i,candidates,target);
        sum -= candidates[i];
        path.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    sort(candidates.begin(),candidates.end());
    backtracking(0,candidates,target);
    return result;
}


