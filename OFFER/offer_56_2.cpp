/*
@File  :offer_56_2.cpp
@Author:dfc
@Date  :2023/1/14  22:57
@Desc  : 数组中出现的次数2
*/
#include "iostream"
#include "vector"
using namespace std;

int singleNumber(vector<int>& nums)
{
    vector<int> count(32,0);
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < count.size(); ++j) {
            count[31-j] += ((nums[i]>>j) & 1);
        }
    }
    int result = 0;
    for (int i = 0; i < count.size(); ++i) {
        count[i] = count[i] %3;
    }
    for (int i = 0; i < count.size(); ++i) {
        result = result <<1;  // 注意 这里两句话的顺序不能反 以第一个为例 其实是应该把最高位通过左移移到最右边 然后喝单独的一个 数字进或运算
        result = result | (count[i]);

    }
    return result;
}

int main()
{
    vector<int> nums = {3,3,5,3};
    cout<<singleNumber(nums);
}
