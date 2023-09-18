/*
@File  :zhongxing_1.cpp
@Author:dfc
@Date  :2023/9/8  18:54
@Desc  :
*/
#include "iostream"
#include "unordered_map"
#include "unordered_set"
#include "vector"
#include "algorithm"
using namespace std;

int main()
{
    int p, q;
    cin>>p>>q;
    vector<int> nums(p);
    for (int i = 0; i < p; ++i) {
        cin>>nums[i];
    }
    unordered_set<int> my_set;
    for (int i = 0; i < q; ++i) {
        int tmp;
        cin>>tmp;
        my_set.insert(tmp);
    }
    vector<int> last;
    unordered_map<int , int> my_map;
    for (int i = 0; i < p; ++i) {
        if (my_set.find(nums[i]) != my_set.end())
        {
            my_map[nums[i]] ++;
        }
        else
        {
            last.push_back(nums[i]);
        }
    }
    sort(last.begin(),last.end());
    vector<int> result;
    for (auto iter : my_set) {
        for (int i = 0; i < my_map[iter]; ++i) {
            result.push_back(iter);
        }
    }
    for (int i = 0; i < last.size(); ++i) {
        result.push_back(last[i]);
    }
    for (int i = 0; i < result.size(); ++i) {
        cout<<result[i]<<" ";
    }
}