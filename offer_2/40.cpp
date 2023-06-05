/*
@File  :40.cpp
@Author:dfc
@Date  :2023/5/23  23:49
@Desc  :
*/
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std ;

vector<int> path;
int sum = 0;
vector<vector<int>> result;

void backtracking(vector<int>& candidates, int target,int start)
{
    if (sum == target)
    {
        result.push_back(path);
        return;
    }
    if (sum>target)
        return;
    for (int i = start; i <=candidates.size()-1  ; ++i) {
        if (i>start and candidates[i]==candidates[i-1]) continue;
        sum += candidates[i];
        path.push_back(candidates[i]);
        backtracking(candidates,target,i+1);
        sum -= candidates[i];
        path.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
    sort(candidates.begin(),candidates.end());
    backtracking(candidates,target,0);
    return result;
}

