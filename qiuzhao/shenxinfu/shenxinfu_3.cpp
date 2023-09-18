/*
@File  :shenxinfu_3.cpp
@Author:dfc
@Date  :2023/9/6  19:58
@Desc  :
*/
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

bool static cmp(const pair<int,int> &a, const pair<int,int> &b)
{
    return a.first<b.first;
}

int main()
{
    int n,d;
    cin>>n>>d;
    vector<pair<int,int>> my_vec;
    for (int i = 0; i < n; ++i) {
        pair<int,int> tmp;
        cin>>tmp.first>>tmp.second;
        my_vec.push_back(tmp);
    }
    sort(my_vec.begin(),my_vec.end(),cmp);
    for (int i = 0; i < my_vec.size(); ++i) {
        cout<<my_vec[i].first<<" "<<my_vec[i].second<<endl;
    }
    int start = 0;
    int result = 0;
    while (start<=my_vec.size()-1)
    {
        int end = start;
        int tmp = 0;
        while (end< my_vec.size() and my_vec[end].first-my_vec[start].first<d)
        {
            tmp+=my_vec[end].second;
            end++;
        }
        result = max(result,tmp);
        start++;
    }
    cout<<result;
}