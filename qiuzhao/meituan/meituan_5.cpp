/*
@File  :meituan_5.cpp
@Author:dfc
@Date  :2023/8/26  10:44
@Desc  :
*/
#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;

int main()
{
    int n , k;
    cin>>n>>k;
    vector<unsigned long long > nums(n);
    unsigned long long  sum = 0;
    vector<unsigned long long >pre_sum(n+1,0);
    unordered_map<unsigned long long , int> my_map;
    my_map[0] = 0;
    for (int i = 0; i < n; ++i) {
        cin>>nums[i];
        sum +=  nums[i];
        pre_sum[i+1] = sum;
    }
    int result = 0;
    for (int i = 1; i < n; ++i) {
        int  length  = 0;
        for (int j = k; j <=pre_sum[i] ; j+=k) {
            if (my_map.find(pre_sum[i]-j) != my_map.end())
            {
                int tmp = my_map[pre_sum[i]-j];
                if ((i-tmp) * k == pre_sum[i] - pre_sum[tmp])
                    length = i - my_map[pre_sum[i]-j];
            }
        }
        result = max(result,length);
        if (my_map.find(pre_sum[i]) == my_map.end())
            my_map[pre_sum[i]  ] = i;
    }
    if (result==0) cout<<-1<<endl;
    else cout<<result<<endl;
}

