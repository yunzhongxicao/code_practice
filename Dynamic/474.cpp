/*
@File  :474.cpp
@Author:dfc
@Date  :2022/11/9  11:22
@Desc  :一和零
*/
#include "string"
#include "iostream"
#include "vector"
using namespace std;

vector<int> num_zero(const string &s)
{
    int num0=0,num1=0;
    for(char c:s)
    {
        if (c=='0') num0++;
        else num1++;
    }
    return vector<int>{num0,num1};
}

/*int findMaxForm(vector<string>& strs, int m, int n)  三维写法
{
    int length = strs.size();
    vector<vector<vector<int>>> dp(length,vector<vector<int>>(m+1,vector<int>(n+1,0)));

    vector<int> tmp = num_zero(strs[0]);
    int tmp0 = tmp[0];
    int tmp1 = tmp[1];

    for (int j =tmp0 ; j <=m ; ++j) {
        for (int k = tmp1; k <=n ; ++k) {
            dp[0][j][k] =1;
        }
    }

    for (int i = 1; i <length ; ++i) {
        tmp = num_zero(strs[i]);  // 这个计算放到后面两个for的前面 对每一层来说 0 和1的数量是确定的
                                 // 亲测 放到后面去会超时
        tmp0 = tmp[0];
        tmp1 = tmp[1];
        for (int j = 0; j <=m ; ++j) {
            for (int k = 0; k <= n; ++k) {
                if (j>=tmp0 and k>=tmp1)
                {
                    dp[i][j][k] = max(dp[i-1][j][k],dp[i-1][j-tmp0][k-tmp1]+1);
                }
                else
                {
                    dp[i][j][k] = dp[i-1][j][k];
                }
            }
        }
    }
    return dp[length-1][m][n];
}*/

int findMaxForm(vector<string>& strs, int m, int n) // 二维写法
{
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    vector<int> tmp = num_zero(strs[0]);
    int tmp0 = tmp[0];
    int tmp1 = tmp[1];

    for (int j =tmp0 ; j <=m ; ++j) {
        for (int k = tmp1; k <=n ; ++k) {
            dp[j][k] =1;
        }
    }

    for (int i = 1; i <strs.size() ; ++i) {
        tmp = num_zero(strs[i]);  // 这个计算放到后面两个for的前面 对每一层来说 0 和1的数量是确定的
        // 亲测 放到后面去会超时
        tmp0 = tmp[0];
        tmp1 = tmp[1];
        for (int j = m; j >=tmp0 ; --j) {
            for (int k = n; k>=tmp1; --k) {
                    dp[j][k] = max(dp[j][k],dp[j-tmp0][k-tmp1]+1);
            }
        }
    }
    return dp[m][n];
}


int main()
{
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    cout<<findMaxForm(strs,5,3);
}


