/*
@File  :shenxinfu_4.cpp
@Author:dfc
@Date  :2023/9/6  20:15
@Desc  :
*/
#include "iostream"
#include "unordered_map"
#include "unordered_set"
#include "algorithm"
#include "vector"
using namespace std;

bool static cmp(const pair<int,int> &a, const pair<int,int> &b)
{
    return a.first>b.first;
}

void solution(vector<int>&nums, int k)
{
    vector<pair<int, int>> my_vec;
    for (int i = 0; i < nums.size(); ++i) {
        pair<int,int> tmp;
        tmp.first= nums[i];
        tmp.second= i;
        my_vec.push_back(tmp);
    }
    sort(my_vec.begin(),my_vec.end(),cmp);
//    for (int i = 0; i < my_vec.size(); ++i) {
//        cout<<my_vec[i].first<<" ";
//    }
//    cout<<endl;
    unordered_set<int> my_set;
    for (int i = 0; i < nums.size()-k ; ++i) {
        my_set.insert(my_vec[i].second); // ÒªÉ¾³ýµÄË÷Òý
    }
    vector<int> real_nums;
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (my_set.find(i) == my_set.end())
        {
            real_nums.push_back(nums[i]);
//            cout<<nums[i]<<" ";
            sum+= nums[i];
        }
    }
//    cout<<endl;
    int sum_tmp =0;
    int result = INT32_MAX;
    for (int i = 0; i < real_nums.size(); ++i) {
        sum_tmp += real_nums[i];
        int result_tmp = max(sum_tmp, sum-sum_tmp);
        result = min(result,result_tmp);
    }
    cout<<result<<endl;
}

int main()
{
    int T;
    cin>>T;
    for (int i = 0; i <T ; ++i) {
        int n ,k;
        cin>>n>>k;
        vector<int> nums(n,0);
        for (int j = 0; j < n; ++j) {
            cin>>nums[j];
        }
        solution(nums,k);
    }
}