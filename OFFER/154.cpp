/*
@File  :154.cpp
@Author:dfc
@Date  :2022/12/8  11:39
@Desc  :
*/
#include "iostream"
#include "vector"
using namespace std;

int findMin(vector<int>& nums)
{
    int left=0,right = nums.size()-1;
    while (left<right)
    {
        int mid = left+(right-left)/2;
        if (nums[mid] > nums[right]) left = mid+1;
        else if (nums[mid]<nums[right]) right = mid;
        else if (nums[mid] == nums[right]) right--; // mid不可能等于right 一定是比right小的 因为mid是向下取整 最多等于left
        // 第三种情况:  nums[mid] == nums[right]。由于重复元素的存在，所以不能确定nums[mid]在最小值的左侧还是右侧，因此我们不能莽撞地忽略某一部分的元素。我们唯一可以知道的是，
//                                      由于它们的值相同，所以无论nums[right]不是最小值，都有一个它的「替代品」nums[mid], 因此我们可以忽略二分查找区间的右端点。
    }
    return nums[left];
}

