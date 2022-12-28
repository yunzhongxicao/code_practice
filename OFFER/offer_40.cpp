/*
@File  :offer_40.cpp
@Author:dfc
@Date  :2022/12/28  11:36
@Desc  : 最小的k个数
*/
#include "iostream"
#include "queue"
#include "vector"
using namespace std;

vector<int> getLeastNumbers(vector<int>& arr, int k)
{
    priority_queue<int,vector<int>,less<>>my_que;
    for (int i = 0; i < arr.size(); ++i) {
        my_que.push(arr[i]);
        if (my_que.size()>k)
        {
            my_que.pop();
        }
    }
    vector<int> result;
    while (!my_que.empty())
    {
        result.push_back(my_que.top());
        my_que.pop();
    }
    return result;
}

int main()
{
    vector<int> arr = {0,1,2,1};
    int k = 3;
    vector<int> result = getLeastNumbers(arr,k);
    for (int i = 0; i < result.size(); ++i) {
        cout<<result[i]<<" ";
    }
}