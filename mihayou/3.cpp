#include "bits/stdc++.h"
using namespace std;

const long long MOD = 1000000007;
int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    for (int i = 0; i < n; ++i) {
        cin>>nums[i];
    }
    // for (int i = 0; i < nums.size(); ++i) {
    //     cout<<nums[i]<<" ";
    // }
    // cout<<endl;
    vector<unsigned long long >dp(n,0);
    // sort(nums.begin(),nums.end());
    dp[0] =0;
    for (int i = 1; i < nums.size(); ++i) {
        for (int j = 0; j <=i-1; ++j) {
            if ((nums[i]>nums[j] and nums[i] % nums[j]==0) or (nums[i]<nums[j] and nums[j]%nums[i]==0))
                dp[i] += (dp[j] +1);
        }
    }
    unsigned long long result =0;
    for (int i = 0; i < dp.size(); ++i) {
        result = (result+dp[i]) % MOD;
    }
    cout<<result;
    return 0;
}
