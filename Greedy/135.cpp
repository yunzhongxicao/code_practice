/*
@File  :135.cpp
@Author:dfc
@Date  :2022/10/31  10:30
@Desc  : ·Ö·¢ÌÇ¹û
*/
#include "iostream"
#include "vector"

using namespace std;

int candy(vector<int>& ratings);

int candy(vector<int>& ratings)
{
    vector<int> candys(ratings.size(),1);
    for (int i = 1; i < ratings.size(); ++i) {
        if (ratings[i]>ratings[i-1]) candys[i] = candys[i-1] +1;
    }
    for (int i = (int)ratings.size()-2; i >=0 ; --i) {
        if (ratings[i]>ratings[i+1]) candys[i] = max(candys[i],candys[i+1]+1);
    }
    int result=0;
    for (int candy : candys) {
        result += candy;
    }
    return result;
}

int main()
{
    vector<int> ratings = {1,0,2};
    int result = candy(ratings);
    cout<<result;
}