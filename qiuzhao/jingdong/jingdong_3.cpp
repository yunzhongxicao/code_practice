/*
@File  :jingdong_3.cpp
@Author:dfc
@Date  :2023/8/19  11:10
@Desc  :
*/
#include "iostream"
#include "vector"
#include "string"

using namespace std;

int main()
{
    int n , m;
    cin>>n>>m;
    vector<string> chess(n,string(m,'1'));
    for (int i = 0; i < n; ++i) {
        cin>>chess[i];
    }
    // chess[0] = "....";
    // chess[1]= "**.*";
    // chess[2]= "....";
    // for (int i = 0; i < n; ++i) {
    //     cout<<chess[i]<<endl;
    // }
    vector<vector<vector<long  long >>>dp(n,vector<vector<long long > >(m,vector<long long >(3,INT32_MAX)));
    // 0 表示 左边 1 表示上面 2表示斜面过来
    for (int j  = 1; j <m ; ++j) {
        if (chess[0][j]=='*')
            break;
        dp[0][j][0] = 1;
    }
    for (int i = 1; i < n; ++i) {
        if (chess[i][0]=='*')
            break;
        dp[i][0][1]    = 1;
    }
    dp[0][0] = vector<long long >{0,0,0};

    for (int i = 1; i <n     ; ++i) {
        for (int j = 1; j <m ; ++j) {
            if (chess[i][j] =='*')
                continue;
            // 从左边过来；
            dp[i][j][0] = min(dp[i][j-1][0], min(dp[i][j-1][1],dp[i][j-1][2])+1);
            if (dp[i][j][0]>INT32_MAX) // 上限就是INT32_MAX
                dp[i][j][0] = INT32_MAX;

            // 从上面下来

            dp[i][j][1] = min(dp[i-1][j][1], min(dp[i-1][j][0],dp[i-1][j][2])+1);
            if (dp[i][j][1]>INT32_MAX) // 上限就是INT32_MAX
                dp[i][j][1] = INT32_MAX;

            // 从侧上方下来
            dp[i][j][2] = min(dp[i-1][j-1][2], min(dp[i-1][j-1][0],dp[i-1][j-1][1])+1);
            if (dp[i][j][2]>INT32_MAX) // 上限就是INT32_MAX
                dp[i][j][2] = INT32_MAX;

        }
    }
    if (dp[n-1][m-1][0]>=INT32_MAX and dp[n-1][m-1][1]>=INT32_MAX and dp[n-1][m-1][2]>=INT32_MAX)
    {
        cout<<-1<<endl;
        return 0;
    }
    cout<<min(dp[n-1][m-1][0], min(dp[n-1][m-1][1], dp[n-1][m-1][2]));
    return 0;
}

