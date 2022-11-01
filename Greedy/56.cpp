/*
@File  :56.cpp
@Author:dfc
@Date  :2022/11/1  19:50
@Desc  : 合并区间
*/
#include "iostream"
#include "vector"
#include "algorithm"
using namespace  std;

bool static cmp(const vector<int> &a, const vector<int> &b)
{
    return a[0]<b[0];
}

vector<vector<int>> merge(vector<vector<int>>& intervals);

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    vector<vector<int>> result;
    sort(intervals.begin(),intervals.end(), cmp);
    int low = intervals[0][0], high = intervals[0][1];
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0]<=high) // 要合并
        {
            high = max(high,intervals[i][1]);
        } else
        {
            result.push_back(vector<int>{low,high});
            low = intervals[i][0];
            high = intervals[i][1];
        }
    }
    result.push_back(vector<int>{low,high}); // 这里是因为最后一次只结束了 没有push进去
    return result;
}