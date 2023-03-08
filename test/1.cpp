/*
@File  :1.cpp
@Author:dfc
@Date  :2023/3/7  19:06
@Desc  :
*/
#include "iostream"
#include "vector"

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a;
    vector<int> cinVec(n);
    for(int i=0;i<n;i++)
    {
        cin>>a;
        cinVec[i] = a;
    }
    // int ans = 0;
    // int start =0;
    // for (int i = 0; i < n; ++i) {
    //     if (i>0 and abs(cinVec[i] - cinVec[i-1]) >1)
    //         start =i;
    //     ans = max(ans,i-start+1);
    // }
    // cout<<ans;
    vector<int>dp(n);
    dp[0] =1;
    int result=0;
    for (int i = 1; i < n; ++i) {
        if (abs(cinVec[i]- cinVec[i-1])<=1)
            dp[i] =dp[i-1]+1;
        else
            dp[i] =1;
        result = max(result,dp[i]);
    }
    cout<<result;
    return 0;
}

