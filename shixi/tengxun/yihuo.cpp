/*
@File  :yihuo.cpp
@Author:dfc
@Date  :2023/3/26  20:51
@Desc  :
*/
#include "bits/stdc++.h"
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    for (int i = 0; i < n; ++i) {
        cin>>nums[i];
    }

    int result =0;
    int start = 0;
    int end;
    for (int i = 0; i < nums.size(); ++i) {
        unsigned long long cheng=1;
        unsigned long long yi = 0;
        for (int j = i; j <nums.size() ; ++j) {
            cheng *= nums[j];
            yi = (yi^nums[j]);
            if (cheng==yi)
                result++;
        }
    }
    cout<<result;
    return 0;
}

