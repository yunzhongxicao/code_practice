/*
@File  :lingxi_5.cpp
@Author:dfc
@Date  :2023/8/27  20:49
@Desc  :
*/
#include "iostream"
#include "vector"

using namespace std;

int main()
{
    vector<vector<int>> dp(21,vector<int>(200,0));
    for (int i = 0; i < dp.size(); ++i) {
        dp[i][0] = 1;
    }

    for (int n = 2; n <21 ; ++n) {
        for (int i = 1; i <n ; ++i) {
            for (int j = 0; j < 200; ++j) {
                if (dp[n-i][j])
                    dp[n][i * (n-i) + j] = 1;
            }
        }
    }
    int N;
    while (cin>>N)
    {
        for (int j = 0; j < dp[0].size(); ++j) {
            if (dp[N][j])
                cout<<j<<" ";
        }
        cout<<endl;
    }
}

