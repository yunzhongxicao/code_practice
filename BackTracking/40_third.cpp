/*
@File  :40_third.cpp
@Author:dfc
@Date  :2023/7/18  21:38
@Desc  :
*/
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

vector<int> path;
int sum = 0;
vector<vector<int>> result;

void backtracking(int start, vector<int>&candidates, int target)
{
    if (sum>target) return;
    if (sum==target)
    {
        result.push_back(path);
        return;
    }
    for (int i = start; i <=candidates.size()-1 ; ++i) {
        if (i>start and candidates[i]==candidates[i-1]) continue;
        path.push_back(candidates[i]);
        sum += candidates[i];
        if (sum>target)
        {
            path.pop_back();
            sum -= candidates[i];
            return;
        }
        backtracking(i+1,candidates,target);
        path.pop_back();
        sum -= candidates[i];
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
    sort(candidates.begin(),candidates.end());
    backtracking(0,candidates,target);
    return result;
}