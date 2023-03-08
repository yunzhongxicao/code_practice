/*
@File  :40_second.cpp
@Author:dfc
@Date  :2023/3/9  0:09
@Desc  :
*/
#include "bits/stdc++.h"

using namespace std;
vector<int>path;
vector<vector<int>> result;
int sum=0;

void backtracking(vector<int>& candidates, int target, int start)
{
    if (sum==target)
    {
        result.push_back(path);
        return;
    }
    if (sum>target)
        return;
    for (int i = start; i <= candidates.size()-1; ++i) {
        if (i>start and candidates[i]== candidates[i-1])
            continue;
        sum += candidates[i];
        if (sum>target)
        {
            sum -= candidates[i];
            break;
        }
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

