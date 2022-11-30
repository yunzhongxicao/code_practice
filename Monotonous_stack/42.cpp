/*
@File  :42.cpp
@Author:dfc
@Date  :2022/11/30  9:25
@Desc  : ����ˮ
*/
#include "iostream"
#include "vector"
#include "stack"
using namespace std;

/*int trap(vector<int>& height) // ���ǵ�һ����뷨 ������ û���뵽�Ǻ��ż���
{
    stack<int> my_stack;
    vector<int> next_greater(height.size(),-1); // �������һ������ֵ������
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
        else if (height[i] == height[my_stack.top()]) // ���������������ʹ��ջ��� ֻ�к������Ҫ��Ϊ�� ���ж�
        {
            my_stack.pop();
            my_stack.push(i); // ���м��㣬 �����ͬ ֻ�ǰѿ��+1 ����������� ֻ�����˸� ����� �ż��� ������Ϊ�ײ���������
        }
        else
        {
            while (!my_stack.empty() and  height[i] > height[my_stack.top()]) {
                int mid = my_stack.top(); // �ײ�
                my_stack.pop();
                if (!my_stack.empty())  // ������һ���п���Ϊ����
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

