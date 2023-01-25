/*
@File  :offer_45.cpp
@Author:dfc
@Date  :2023/1/25  17:28
@Desc  : 把数组排成最小的数
*/
#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
using namespace std;

static bool cmp(const string &a, const string &b)
{
    return (a+b) < (b+a);
}

string minNumber(vector<int>& nums)
{
    vector<string>nums_str(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
        nums_str[i] = to_string(nums[i]);
    }
    sort(nums_str.begin(),nums_str.end(),cmp);
    string result="";
    for (int i = 0; i < nums_str.size(); ++i) {
        result +=nums_str[i];
    }
    return result;
}

int main()
{
    vector<string> a = {"30","34","3"};
    sort(a.begin(),a.end(),cmp);
    for (int i = 0; i < a.size(); ++i) {
        cout<<a[i]<<" ";
    }
}

