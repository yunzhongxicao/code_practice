/*
@File  :279.cpp
@Author:dfc
@Date  :2022/11/14  10:41
@Desc  : ��ȫƽ����
*/
#include "iostream"
#include "vector"
#include "cmath"
using namespace std;

/*int numSquares(int n) // ��ά��д��
{
    int max_index = sqrt(n);
    vector<vector<int>> dp(max_index+1,vector<int>(n+1,0)); // ����ѵ�0�зŽ���ֻ��Ϊ�������������ֱȽ�һ��һ�� û�������
    int tmp=1;
    while (tmp*1<=n)
    {
        dp[1][tmp*1] = tmp;
        tmp++;
    }
    for (int i = 2; i <=max_index ; ++i) {
        for (int j = 1; j <=n ; ++j) {
            if (j<i*i)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = min(dp[i-1][j],dp[i][j-i*i]+1);
        }
    }
    return dp[max_index][n];
}*/

int numSquares(int n)  // һά��д��
{
    int max_index = sqrt(n);
    vector<int>dp(n+1,0);
    int tmp=1;
    while (tmp*1<=n)
    {
        dp[tmp*1] = tmp;
        tmp++;
    }
    for (int i = 2; i <=max_index ; ++i) {
        for (int j = i*i; j <=n ; ++j) {
            dp[j] = min(dp[j],dp[j-i*i]+1 );
        }
    }
    return dp[n];

}


int main()
{
    cout<<numSquares(12);
}

