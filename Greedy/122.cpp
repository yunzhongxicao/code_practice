/*
@File  :122.cpp
@Author:dfc
@Date  :2022/10/28  10:28
@Desc  : ������Ʊ�����ʱ��
*/

#include "iostream"
#include "vector"
using namespace std;

/*int maxProfit(vector<int>& prices) //��ʵ��֮ǰ�ڶ�������һ���� ���ǵ͵����� �ߵ�����
 * ���� �����鷳�� ��̰�ĵ��㷨����
{
    int last_diff=0;
    int buy_in=0;
    int cur_diff=0;
    int profit=0;
    int flag=0;
    if (prices.size()==1) return 0;
    for (int i = 1; i < prices.size(); ++i) {
        cur_diff = prices[i] - prices[i-1];
        if (cur_diff>=0 and last_diff<=0) // �����
        {
            last_diff = cur_diff;
            buy_in = prices[i-1];
            flag = 1;
        }
        else if (cur_diff<0 and last_diff>=0 and flag==1) // �����㣬����Ҫע�����һ�������½������޷������� ��Ҫ������
        {
            last_diff = cur_diff;
            profit = profit + prices[i-1] - buy_in;

        }
    }
    // ���һ��Ҫ�������� ��Ϊת�۵�û�а������ȥ
    if (cur_diff>=0)
        profit = profit + prices[(int)prices.size()-1] - buy_in; // �ٴ�����
    return profit;
}*/

int maxProfit(vector<int>& prices) // ��ȥ���ǵ͵����� �ߵ����� ֻ����ÿһ�������
                                    // ��һ����������ɺܶ��С���� �൱��ÿ�춼���� ���ǿ���Щ�����õ�
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

