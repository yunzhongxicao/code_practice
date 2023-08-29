/*
@File  :xiaohongshu_3.cpp
@Author:dfc
@Date  :2023/7/23  19:49
@Desc  :
*/
#include "iostream"
#include "vector"

using namespace std;

vector<long long> get_sum(vector<long long> &nums)
{
    long long  sum = nums[0];
    long long  result = sum;
    int start = 0, end = 0;
    int final_start=0, final_end=0;
    for (int i = 1; i <=nums.size()-1 ; ++i) {
        if (sum<0)
        {
            sum = nums[i];
            start = i;
            end = i;
        }
        else
        {
            sum += nums[i];
            end = i;
        }
        if(sum>result)
        {
            result = sum;
            final_start = start;
            final_end = end;
        }
    }
    return vector<long long>{result, final_start,final_end};
}

long long   solution( vector<long long > &nums, long long  x)
{
    vector<vector<long long >> dp(nums.size(), vector<long long >(2));
    dp[0][0] = nums[0];
    dp[0][1] = x;
    long long result = max(dp[0][0],dp[0][1]);
    for(int i =1; i<nums.size(); i++)
    {
        dp[i][0] = max(max(dp[i-1][0],dp[i-1][1])+nums[i], nums[i]);
        dp[i][1] = max(dp[i-1][0]+x, x);
        result = max(max(dp[i][0],dp[i][1]),result);
    }
    return result;
}

int main()
{
    int t;
    cin>>t;
    int n;
    long long x;
    vector<long long> nums;
    for (int i = 0; i <t ; ++i) {
        cin>>n>>x;
        nums.clear();
        nums.resize(n);
        for (int j = 0; j <n ; ++j) {
            cin>>nums[j];
        }
        cout<<solution(nums, x);
    }
}

