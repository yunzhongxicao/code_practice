/*
@File  :offer_57_2.cpp
@Author:dfc
@Date  :2023/1/15  10:47
@Desc  : 和为s的连续正数序列
*/
#include "iostream"
#include "vector"
using namespace std;
vector<vector<int>> findContinuousSequence(int target)
{
    int left =1, right = 2;

    if (target<3) return vector<vector<int>>{{}};
    vector<vector<int>> result;
    int sum = left+right;
    while (left<right and right<=target/2+1)
    {
        if (sum<target)
        {
            right++;
            sum+=right;
        }
        else if (sum>target)
        {
            sum -= left;
            left++;
        } else
        {
            vector<int> path;
            for (int i = left; i <=right ; ++i) {
                path.push_back(i);
            }
            result.push_back(path);
            right++;
            sum+=right;
            sum -= left;
            left++;
        }
    }
    return result;
}
