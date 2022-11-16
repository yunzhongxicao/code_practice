/*
@File  :121.cpp
@Author:dfc
@Date  :2022/11/15  18:57
@Desc  :������Ʊ�����ʱ��
*/
#include "vector"
#include "iostream"
using namespace std;

int maxProfit(vector<int>& prices)
{
    vector<int>dp(prices.size()); // 0-->i����͵�
    dp[0] = prices[0];
    int result = 0;
    for (int i = 1; i < prices.size(); ++i) {
        dp[i] = min(dp[i-1],prices[i]);
        result = max(result,prices[i]-dp[i]);
    }
    return result;
}

/*int maxProfit(vector<int>& prices) // ֻ����һ��
{
    int buy_in = INT32_MAX;
    int result = 0;
    for (int i = 0; i < prices.size(); ++i) { // ������i��������Ʊ ��ôһ������0-->i������СֵȻ������ ����һ�����ֵ����
        buy_in=min(buy_in,prices[i]);
        result  = max(result,prices[i]-buy_in);
    }
    return result;
}*/


int main()
{
    vector<int> prices={7,1,5,3,6,4};
    cout<<maxProfit(prices);
}

