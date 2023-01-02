/*
@File  :offer_46 °ÑÊý×Ö·­Òë³É×Ö·û´®.cpp
@Author:dfc
@Date  :2023/1/1  23:07
@Desc  : °ÑÊý×Ö·­Òë³É×Ö·û´®
*/
#include "vector"
#include "iostream"
#include "string"
using namespace std;
int translateNum(int num)
{
    string num_s = to_string(num);
    vector<int> dp(num_s.size()+1,0);
    dp[0] = 1;

    dp[1]=1;
    for (int i = 2; i <=num_s.size() ; ++i) {
        dp[i] = dp[i-1];
        int tmp = stoi(num_s.substr(i-2,2));
        if (tmp>=10 and tmp<=25)
            dp[i] += dp[i-2];
    }
    return dp[num_s.size()];
}

int main()
{
    cout<<translateNum(25);
}

