/*
@File  :gongyueshu.cpp
@Author:dfc
@Date  :2023/3/26  21:06
@Desc  :
*/
#include <iostream>
#include <vector>
using namespace std;

constexpr int MOD = 1e9 + 7;

int gcd(int a, int b) {
    if (b==0) return a;
    else return gcd(b,a%b);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int max_value = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        max_value = max(max_value,a[i]);
    }
    vector<vector<unsigned long long >> dp(n + 1, vector<unsigned long long >(max_value, 0));
    dp[0][0] = 1; // 空序列的最大公约数为 0

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= max_value-1; ++j) {
            // 如果不选择当前元素 a[i]
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]);
            // 如果选择当前元素 a[i]
            int new_gcd = gcd(j, a[i]);
            dp[i + 1][new_gcd] = (dp[i + 1][new_gcd] + dp[i][j]);
        }
    }
    unsigned long long ans = dp[n][k];
    cout << ans % MOD<< endl;

    return 0;
}


