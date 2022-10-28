/*
@File  :122.cpp
@Author:dfc
@Date  :2022/10/28  10:28
@Desc  : 买卖股票的最佳时机
*/

#include "iostream"
#include "vector"
using namespace std;

/*int maxProfit(vector<int>& prices) //其实和之前摆动序列是一样的 都是低点买入 高点卖出
 * 但是 还是麻烦了 用贪心的算法更好
{
    int last_diff=0;
    int buy_in=0;
    int cur_diff=0;
    int profit=0;
    int flag=0;
    if (prices.size()==1) return 0;
    for (int i = 1; i < prices.size(); ++i) {
        cur_diff = prices[i] - prices[i-1];
        if (cur_diff>=0 and last_diff<=0) // 买入点
        {
            last_diff = cur_diff;
            buy_in = prices[i-1];
            flag = 1;
        }
        else if (cur_diff<0 and last_diff>=0 and flag==1) // 卖出点，但是要注意如果一来就是下降沿是无法卖出的 需要先买入
        {
            last_diff = cur_diff;
            profit = profit + prices[i-1] - buy_in;

        }
    }
    // 最后一个要单独考虑 因为转折点没有把它算进去
    if (cur_diff>=0)
        profit = profit + prices[(int)prices.size()-1] - buy_in; // 再次卖出
    return profit;
}*/

int maxProfit(vector<int>& prices) // 不去考虑低点买入 高点卖出 只考虑每一天的利润
                                    // 把一个大区间拆解成很多个小区间 相当于每天都买入 但是看哪些天有用的
{
    int result=0;
    if (prices.size()==1) return result;
    for (int i = 1; i < prices.size(); ++i) {
        if (prices[i]- prices[i-1]>0)
            result = result + prices[i] - prices[i-1];
    }
    return result;
}

int  main()
{
    vector<int> prices= {7,1,5,3,6,4};
    int result = maxProfit(prices);
    cout<<result;
}

