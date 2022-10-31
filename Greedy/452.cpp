/*
@File  :452.cpp
@Author:dfc
@Date  :2022/10/31  14:25
@Desc  : 用最少数量的箭引爆气球
*/


#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

bool static cmp(const vector<int>&a, const vector<int>&b)
{
    return a[0]<b[0];
}

int findMinArrowShots(vector<vector<int>>& points)
{
    sort(points.begin(),points.end(),cmp);
    int low=points[0][0], high = points[0][1];
    int result=1;
    for (int i = 1; i < points.size(); ++i) {
        if (points[i][0]<=high)
        {
            low = points[i][0];
            high = min(high,points[i][1]);
        }
        else
        {
            result++;
            low = points[i][0];
            high = points[i][1];
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> points = {{1,2},{2,3},{3,4},{4,5}};
    int result = findMinArrowShots(points);
    cout<<result;
}