/*
@File  :121.cpp
@Author:dfc
@Date  :2022/11/15  18:57
@Desc  :������Ʊ�����ʱ��
*/
#include "vector"
#include "iostream"
using namespace std;

/*int maxProfit(vector<int>& prices)
{
    vector<int>dp(prices.size()); // 0-->i����͵�
    dp[0] = prices[0];
    int result = 0;
    for (int i = 1; i < prices.size(); ++i) {
        dp[i] = min(dp[i-1],prices[i]);
        result = max(result,prices[i]-dp[i]);
    }
    return result;
}*/

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


/*int maxProfit(vector<int>& prices) // Z�����Ķ�̬�滮
{
    vector<vector<int>>dp(prices.size(),vector<int>(2));
    dp[0][0] = -prices[0];
    dp[0][1] = 0;

    for (int i = 1; i < prices.size() ; ++i) {
        dp[i][0] = max(dp[i-1][0],-prices[i]); // ע�� ����ֻ������һ��  �������ﲻ��dp[i-1][1]-prices[i]
        dp[i][1] = max(dp[i-1][1],dp[i-1][0]+ prices[i]);
    }
    return dp[prices.size()-1][1];

}*/

int maxProfit(vector<int>& prices) // ��̬�滮�Ż��汾
{
    int dp_i_0=-prices[0];
    int dp_i_1 = 0;

    for (int i = 1; i < prices.size() ; ++i) {
        dp_i_1 = max(dp_i_1,dp_i_0+ prices[i]);// ˳���ܷ� ����dp_i_0�͸����� ������һ������
        dp_i_0 = max(dp_i_0,-prices[i]);
    }
    return dp_i_1;
}

int main()
{
    vector<int> prices={7,1,5,3,6,4};
    cout<<maxProfit(prices);
}

