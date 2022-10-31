/*
@File  :435.cpp
@Author:dfc
@Date  :2022/10/31  14:50
@Desc  : ���ص�����
*/

#include "algorithm"
#include "iostream"
#include "vector"

using namespace std;

bool static cmp(const vector<int>&a, const vector<int>&b)
{
    return a[0]<b[0];
}

int eraseOverlapIntervals(vector<vector<int>>& intervals);
int eraseOverlapIntervals(vector<vector<int>>& intervals)
{
    sort(intervals.begin(),intervals.end(),cmp);
    int low = intervals[0][0],high = intervals[0][1];
    int result=0;
    for (int i = 1; i < intervals.size() ; ++i) {
        if (intervals[i][0]>=high)
        {
            low = intervals[i][0];
            high = intervals[i][1];
        }
        else // ��ʱ����Ҫ�Ƴ��� �����Ƴ��ĸ���Ҫ�ж�һ��
        {
            result++;
            if (intervals[i][1]<high)
            {
                low = intervals[i][0];
                high = intervals[i][1];
            }
        }
    }
    return result;
}


