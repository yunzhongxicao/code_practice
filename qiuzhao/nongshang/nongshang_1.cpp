/*
@File  :nongshang_1.cpp
@Author:dfc
@Date  :2023/8/5  18:51
@Desc  :
*/
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> origin_vec(n,0);
    for (int i = 0; i < n; ++i) {
        cin>>origin_vec[i];
    }
    sort(origin_vec.begin(),origin_vec.end());  // 排序

    vector<int> nums;
    for (int i = 0; i < origin_vec.size(); ++i) {  // 去重
        if (i>=1 and origin_vec[i] == origin_vec[i-1])
            continue;
        else
            nums.push_back(origin_vec[i]);
    }
    vector<int> dp(nums.size(),1);
    dp[0] = 1;
    for (int i = 1; i <=nums.size()-1 ; ++i) {
        if ( (nums[i] % 2 ==0 and nums[i-1] % 2 !=0)   or   (nums[i] % 2 !=0 and nums[i-1] % 2 ==0))  // 奇数偶数不一致就+1
            dp[i] = dp[i-1] +1;
        else
            dp[i] = dp[i-1];
    }
    int result = 0;
    for (int i = 0; i < dp.size(); ++i) {
        if (dp[i]>result)
            result = dp[i];
    }
    cout<<result;
}

