/*
@File  :904.cpp
@Author:dfc
@Date  :2022/8/23  10:28
@Desc  :  水果成篮
*/

#include "iostream"
#include "vector"
using namespace std;

int totalFruit(vector<int>& fruits);

int main()
{
    vector<int> a = {1,2,3,2,2};
    totalFruit(a);
}

int totalFruit(vector<int>& fruits)
{
    int j = 0;
    int sub_length = 0;
    int fruit_1 = fruits[0];
    int fruit_2 = INT32_MIN;
    int result = 0;
    for (int i = 0; i < fruits.size() ; ++i) {
        if (fruits[i] == fruit_1 or fruits[i] == fruit_2)  // 前面这两个if是为了确定最开始两个水果的值，因为一开始肯定是可以一直加的
        {
            sub_length++;
            result = result<sub_length?sub_length:result;

        } else if(fruit_2 == INT32_MIN)
        {
            fruit_2 = fruits[i];
            // j = i;
            sub_length++;
            result = result<sub_length?sub_length:result;

        }
        if (fruit_2 != INT32_MIN)   //这里是一定要等到第二个水果有值之后，才进行判断新出现的
        {
            if (fruits[i] != fruit_1 and fruits[i] != fruit_2)
            {
                fruit_2 = fruits[i];
                fruit_1 = fruits[i-1];  // 滑动窗口从新出现的往左滑动，因为只需要知道两个水果是啥就行，不需要知道位置
                j = i-1;
                sub_length= 1;
                while (fruits[j] == fruit_1)
                {
                    j--;
                    sub_length++;
                }
                result = result<sub_length?sub_length:result;

            }
        }

    }
    cout<<result;
    return result;
}
