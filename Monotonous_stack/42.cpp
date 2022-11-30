/*
@File  :42.cpp
@Author:dfc
@Date  :2022/11/30  9:25
@Desc  : 接雨水
*/
#include "iostream"
#include "vector"
#include "stack"
using namespace std;

/*int trap(vector<int>& height) // 这是第一版的想法 有问题 没有想到是横着计算
{
    stack<int> my_stack;
    vector<int> next_greater(height.size(),-1); // 存的是下一个更大值的索引
    for (int i = 0; i < height.size(); ++i) {
        while (!my_stack.empty() and height[i]>= height[my_stack.top()])
        {
            next_greater[my_stack.top()] = i;
            my_stack.pop();
        }
        my_stack.push(i);
    }
    int start = 0;
    int end;
    int result=0;
    while (start<height.size())
    {
        end = next_greater[start];
        if (end==-1)
        {
            start++;
        }
        else
        {
            int sum=0;
            for (int j = start; j <=end-1 ; ++j) {
                sum+= height[j];
            }
            result += height[start]*(end-start) - sum;
            start = end;
        }

    }
    return result;
}*/

int trap(vector<int>& height)
{
    stack<int>my_stack;
    int  result =0;
    if (height.size()==0)   return result;
    my_stack.push(0);
    for (int i = 1; i < height.size(); ++i) {
        if (height[i]<height[my_stack.top()])
            my_stack.push(i);
        else if (height[i] == height[my_stack.top()]) // 这两种情况都不会使得栈变空 只有后面才需要不为空 的判断
        {
            my_stack.pop();
            my_stack.push(i); // 按行计算， 如果相同 只是把宽度+1 并不参与计算 只有来了个 更大的 才计算 它是作为底部参与计算的
        }
        else
        {
            while (!my_stack.empty() and  height[i] > height[my_stack.top()]) {
                int mid = my_stack.top(); // 底部
                my_stack.pop();
                if (!my_stack.empty())  // 弹出了一次有可能为空了
                {
                    int start = my_stack.top();
                    int end = i;
                    int h = min(height[start], height[end]) - height[mid];
                    int w = end - start-1;
                    result += h * w;
                }
            }
            my_stack.push(i);
        }
    }
    return result;
}

int main()
{
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trap(height);
}

