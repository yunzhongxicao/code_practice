/*
@File  :904_second.cpp
@Author:dfc
@Date  :2023/2/9  14:30
@Desc  : 水果成篮
*/
#include "vector"
#include "iostream"
using namespace std;

int totalFruit(vector<int>& fruits)
{
    int fruit_1 = fruits[0];
    int fruit_2 = fruits.size()+1; // 之所以这样设置是看题目说不会取到这个数
    int start =0 ,end=0;
    int result =0 ;
    while (end<fruits.size())
    {
        if (fruits[end]== fruit_1 or fruits[end]== fruit_2  )
        {
            int temp = end - start+1;
            result = max(result,temp);
            end++;
        }
        else
        {
            fruit_1 = fruits[end-1];
            start = end-1;
            while (start>=0 and fruits[start]==fruit_1  )
            {
                start--;
            }
            start++;
            fruit_2= fruits[end];
        }
    }
    return result;
}

int main()
{
    vector<int> fruits = {3,3,3,1,2,1,1,2,3,3,4};
    cout<<totalFruit(fruits);
}
