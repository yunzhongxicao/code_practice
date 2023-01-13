/*
@File  :offer_56_1.cpp
@Author:dfc
@Date  :2023/1/13  14:40
@Desc  : 数组中数字出现的次数
*/
#include "iostream"
#include "vector"
using namespace std;
vector<int> singleNumbers(vector<int>& nums)
{
    int k = 0;
    for (int i = 0; i < nums.size(); ++i) {
        k = (k^nums[i]);
    }
    int mask = 1;
    while ((mask & k)==0)
         mask = mask<<1;
    // 直到找到了第一个k为1的位  那么就是在这个位上 x 和y不同 可以借此将其分开
    int x=0,y=0;
    for (int i = 0; i < nums.size(); ++i) {
        if ((nums[i]&mask) == 0)
        {
            x = (x^nums[i]);
        }
        else
        {
            y = (y^nums[i]);
        }
    }
    cout<<x<<" "<<y;
    return vector<int>{x,y};
}

int main()
{
    vector<int> nums={1,2,5,2};
    singleNumbers(nums);
}

