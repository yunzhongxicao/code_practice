/*
@File  :bag.cpp
@Author:dfc
@Date  :2022/11/7  11:21
@Desc  :��������
*/
#include "vector"
#include "iostream"

using namespace std;

void test_2_wei_bag_problem()
{
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    // ��ʼ��
    vector<vector<int>> dp(weight.size(),vector<int>(bagWeight+1,0));

    // ��ʵֻ��ʼ���˵�һ��
    for (int j = 0; j <=bagWeight ; ++j) {
        if (j>=weight[0]) dp[0][j]=value[0];
    }

    for (int i = 1; i <=weight.size()-1 ; ++i) {
        for (int j = 1; j <=bagWeight ; ++j) {
            if (j<weight[i]) dp[i][j] = dp[i-1][j];
            else
            {
                dp[i][j] = max(dp[i-1][j],value[i]+dp[i-1][j-weight[i]]);
            }
        }
    }
    cout << dp[weight.size() - 1][bagWeight] << endl;
}

void test_1_wei_bag_problem()
{
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    // ��ʼ��
    vector<int> dp(bagWeight+1,0);
    for (int i = 0; i < weight.size(); ++i) {
        for (int j = bagWeight; j >=weight[i] ; --j) {
            dp[j] = max(dp[j],dp[j-weight[i]]+value[i]);
        }
    }

    cout<<dp[bagWeight];
}

void test_complete_bag_2_wei()
{
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;
    
    vector<vector<int>> dp(weight.size(),vector<int>(bagWeight+1,0));
    int tmp=1;
    while (tmp*weight[0]<=bagWeight) // ��ʼ����һ��
    {
        dp[0][tmp*weight[0]] = value[0] * tmp;
        tmp++;
    }

    for (int i = 1; i <weight.size() ; ++i) {
        for (int j = 0; j <=bagWeight ; ++j) {
            if (j<weight[i])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-weight[i]]+value[i]);
        }
    }
    for (int i = 0; i < dp.size(); ++i) {
        for (int j = 0; j < dp[i].size(); ++j) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[weight.size()-1][bagWeight];
}

void test_complete_bag_1_wei()
{
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    vector<int>  dp(bagWeight+1,0);

    int tmp=1;
    while (tmp*weight[0]<=bagWeight) // ��ʼ����һ��
    {
        dp[tmp*weight[0]] = value[0] * tmp;
        tmp++;
    }
    for (int k = 0; k <=bagWeight ; ++k) { // ��ӡ�����õ�
        cout<<dp[k]<<"  ";
    }
    cout<<endl;

    for (int i = 1; i <weight.size() ; ++i) {
        for (int j = weight[i]; j <=bagWeight ; ++j) {
            dp[j] = max(dp[j],dp[j-weight[i]]+value[i]);
        }

        for (int k = 0; k <=bagWeight ; ++k) { // ��ӡ�����õ�
            cout<<dp[k]<<"  ";
        }
        cout<<endl;
    }

    cout<<dp[bagWeight];
}


int main()
{
    // test_1_wei_bag_problem();
    test_complete_bag_1_wei();
}

