/*
@File  :lingxi_2.cpp
@Author:dfc
@Date  :2023/8/27  19:27
@Desc  :
*/
#include "iostream"
#include "vector"
#include "deque"
#include "algorithm"

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i <n; ++i) {
        cin>>nums[i];
    }

    deque<int> zeng, jian;
    int left = 0, right = 0, result = 0;
    while (right<nums.size())
    {
        while (!jian.empty() and nums[right]>=nums[jian.back()])
            jian.pop_back();
        while (!zeng.empty() and nums[right] <= nums[zeng.back()])
            zeng.pop_back();
        jian.push_back(right);
        zeng.push_back(right);
        while (abs(nums[jian.front()] - nums[zeng.front()]  ) >1)
        {
            left++;
            if (!jian.empty() and jian.front()<left)
                jian.pop_front();
            if (!zeng.empty() and zeng.front()<left)
                zeng.pop_front();
        }
        result = max(result, right-left +1);
        right++;
    }
    cout<<result<<endl;
}

