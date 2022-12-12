/*
@File  :offer_14_2.cpp
@Author:dfc
@Date  :2022/12/12  10:12
@Desc  :������2
*/
#include "iostream"
#include "vector"
using namespace std;

/*int cuttingRope(int n) // �𰸴��� ���ǻ����������ԭ�� �²���max������
{
    vector<unsigned long long >dp(n+1,0); // dp[i]��ʾ����Ϊn�����ӵ����˻�
    dp[2] = 1;
    for (int i = 3; i <=n ; ++i) {
        for (int j = 1; j <=i-2 ; ++j) {
            dp[i] = max(dp[i] % 1000000007, max(((unsigned long long )j * dp[i-j]) %  1000000007, ((unsigned long long )j * (i-j))  % 1000000007));
        }
    }
    return (int)dp[n] % 1000000007;
}*/

int cuttingRope(int n)
{
    if (n==2) return 1;
    if (n==3) return 3;
    if (n==4) return 4;
    long mod = 1000000007;
    long result =1;
    while (n>=5) // ʣ�����4��ʱ��Ͳ����ý�ȥ��3��
    {
        result = result *3;
        result = result % mod;
        n = n-3;
    }
    return (int) (n * result % mod);
}

