/*
@File  :343.cpp
@Author:dfc
@Date  :2022/11/6  12:50
@Desc  : �������
*/
#include "vector"
#include "iostream"
using namespace std;

int integerBreak(int n)
{
    vector<int> dp(n+1);
//    dp[0]=0;  //��������ʼ��û������
//    dp[1]=1;
    dp[2]=1;
    for (int i = 3; i <=n ; ++i) {
        int max_value = 0; // max_valueֻ����ÿ�μ���dp[i]��ʱ������ж�
        for (int j = 1; j <i-1 ; ++j) { // ����ֻ��n-2���� ��Ϊn-1��j=1��ʱ���жϹ��� Ҳ���Աܿ�dp[1]û�����������
            max_value= max(max_value, max(j*(i-j),j*dp[i-j]));
        }
        dp[i] = max_value;
    }
    return dp[n];
}

int main()
{
    int result = integerBreak(10);
    cout<<result;
}