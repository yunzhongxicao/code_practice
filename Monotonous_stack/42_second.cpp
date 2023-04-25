/*
@File  :42_second.cpp
@Author:dfc
@Date  :2023/4/25  11:43
@Desc  :
*/
#include "iostream"
#include "vector"
#include "stack"

using namespace std;

int trap(vector<int>& height)
{
    int start = 0;
    int result = 0;
    while (height[start]==0)
        start++;
    stack<int> my_stack;
    for (int i = start; i <height.size() ; ++i) {
        int end = i;
        while (!my_stack.empty() and height[i]>=height[my_stack.top()])
        {
            end = my_stack.top();
            my_stack.pop();
        }
        if (end<i)
        {
            int orc =0 ;
            for (int j = end; j <=i-1 ; ++j) {
                orc += height[j];
            }
            int temp = (i-end) * height[end] - orc;
            result += temp;
        }
        my_stack.push(i);
    }
    return result;
}

int main()
{
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trap(height);
}