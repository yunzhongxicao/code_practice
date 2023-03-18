/*
@File  :1.cpp
@Author:dfc
@Date  :2023/3/18  15:07
@Desc  :
*/

#include "bits/stdc++.h"
using namespace std;
vector<int>path;
vector<vector<int>>result;

void bfs(vector<int>&damages, int start, int last_num)
{
    if (path.size()==3)
    {
        result.push_back(path);
        return;
    }
    for (int i = start; i < damages.size(); ++i) {
        if (damages[i]>last_num)
        {
            path.push_back(damages[i]);
            bfs(damages,i+1,damages[i]);
            path.pop_back();
        }
    }
}

int FindSkillGroup(vector<int>& damages)
{
    bfs(damages,0,INT32_MIN);
    return result.size();
}
