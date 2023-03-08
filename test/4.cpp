/*
@File  :4.cpp
@Author:dfc
@Date  :2023/3/7  20:07
@Desc  :
*/
#include "iostream"
#include "vector"

using namespace std;

int maxlove(int num, int money, vector<int>prize, vector<int>like)
{
    auto max = [](int a, int b) {return a>b? a:b;};
    vector<vector<int>> dp(num+2, vector<int>(money+1,0));
    for (int i = 1; i < num+1; ++i) {
        for (int p = 1; p < money+1; ++p) {
            int t = 0;
            if (i>1 and p>=prize[i-1] /2 + prize[i-2])
                t = like[i-1] + like[i-2] + dp[i-2][p-prize[i-1]/2 - prize[i-2]];
            if (p>=prize[i-1])
                t = max(t,like[i-1] + dp[i-1][p-prize[i-1]]);
            dp[i][p] = max(t,dp[i-1][p]);
        }
    }
    return dp[num][money];
}

int main()
{
    int n ,x    ;
    cin>>n>>x;
    vector<int>prices(n);
    vector<int>loves(n);
    int min_p = INT32_MAX;
    for (int i = 0; i < n; ++i) {
        cin>>prices[i];
        min_p = min(min_p,prices[i]);
    }
    for (int i = 0; i < n; ++i) {
        cin>>loves[i];
    }
    // for (int i = 0; i < n; ++i) {
    //     cout<<prices[i]<<" ";
    // }
    // cout<<endl;
    // for (int i = 0; i < n; ++i) {
    //     cout<<loves[i]<<" ";
    // }
    if (x<min_p)
    {
        cout<<0;
        return 0;
    }
    int result = maxlove(n,x,prices,loves);
    cout<<result;
    return 0;
}

