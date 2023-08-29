/*
@File  :lingxi_3.cpp
@Author:dfc
@Date  :2023/8/27  20:02
@Desc  :
*/
#include "iostream"
#include "vector"
#include "unordered_map"
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> nums(n,0);
    for (int i = 0; i < n; ++i) {
        cin>>nums[i];
    }
    unordered_map<int, vector<int>> my_map;
    int result =INT32_MAX;
    for (int i = 0; i < n; ++i) {
        if (my_map.find(nums[i]) != my_map.end())
        {
            int tmp = i - my_map[nums[i]].back()+1;
            result = min(result,tmp);
            my_map[nums[i]] .push_back(i);
        }
        else
        {
            my_map[nums[i]] .push_back(i);
        }
    }
    cout<<result<<endl;
}

