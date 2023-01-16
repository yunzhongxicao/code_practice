/*
@File  :offer_60.cpp
@Author:dfc
@Date  :2023/1/16  15:25
@Desc  : n�����ӵĵ���
*/
#include "iostream"
#include "vector"
#include "cmath"
using namespace std;

vector<double> dicesProbability(int n)
{
    vector<vector<int>>dp(6*n+1, vector<int>(n+1,0)); // dp[i][j]��ʾ��Ϊi ��Ϊj�ķ�����
    for (int i = 1; i <=6 ; ++i) {
        dp[i][1] = 1;
    }
    for(int j=2;j<=n;++j)
    {
        for(int i=j;i<=6*j;++i)
        {
            for (int k = 1; k <=6 ; ++k) { // k���Լ��ṩ�� i-k���������ṩ��
                if (i-k>=j-1) // �������ṩ�ı�����ڸ�����������
                    dp[i][j] += dp[i-k][j-1];
            }
        }
    }
    vector<double> result(5*n+1);
    for (int i = n; i <=6*n ; ++i) {
        result[i-n] =(double ) dp[i][n] * (1/pow(6,n) );
    }
    return result;
}

int  main()
{
    vector<double>result = dicesProbability(3);
    for (int i = 0; i < result.size(); ++i) {
        cout<<result[i]<<" ";
    }
}

