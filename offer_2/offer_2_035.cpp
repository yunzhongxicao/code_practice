/*
@File  :offer_2_035.cpp
@Author:dfc
@Date  :2023/4/17  16:44
@Desc  :
*/
#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
using namespace std;

int get_minutes(const string &time_s)
{
    int hour = (time_s[0]-'0') * 10 + (time_s[1]-'0');
    int minute = (time_s[3]-'0') * 10 + (time_s[4]-'0');
    return hour * 60 +minute;
}

int findMinDifference(vector<string>& timePoints)
{
    vector<int>times(timePoints.size());
    if (timePoints.size()>24 * 60) return 0;
    for (int i = 0; i < timePoints.size(); ++i) {
        int  time = get_minutes(timePoints[i]);
        times[i] = time;
    }
    sort(times.begin(),times.end());
    int  result  = INT32_MAX;
    for (int i = 1; i <= times.size()-1 ; ++i) {
        result =min(result,times[i] - times[i-1]  );
    }
    result = min(result,times[0]+24*60-times.back());
    return result;
}

