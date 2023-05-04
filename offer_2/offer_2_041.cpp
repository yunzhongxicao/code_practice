/*
@File  :offer_2_041.cpp
@Author:dfc
@Date  :2023/5/3  19:11
@Desc  :
*/
#include "iostream"
#include "vector"
#include "deque"
using namespace std;

class MovingAverage {
public:
    /** Initialize your data structure here. */
    int _size;
    int count = 0;
    double sum = 0;
    deque<int> nums;
    MovingAverage(int size) {
        _size = size;
        count = 0;
        //nums.resize(size);
    }

    double next(int val) {
        if (count<_size)
        {
            sum += val;
            nums.push_back(val);
            count++;
            return sum/count;
        }
        else
        {
            sum = sum - nums[0] + val;
            nums.pop_front();
            nums.push_back(val);
            return sum / count;
        }
    }
};

int main()
{
     MovingAverage *obj = new MovingAverage(3);
     cout<<obj->next(1)<<"  ";
     cout<<obj->next(10)<<"  ";
     cout<<obj->next(3)<<"  ";
     cout<<obj->next(5)<<"  ";
}
