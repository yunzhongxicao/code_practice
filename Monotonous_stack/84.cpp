/*
@File  :84.cpp
@Author:dfc
@Date  :2022/11/30  10:36
@Desc  : ��״ͼ�����ľ���
*/
#include "iostream"
#include "vector"
#include "stack"

using namespace std;

int largestRectangleArea(vector<int>& heights)
{
    stack<int> my_stack;
    heights.push_back(-1);
    my_stack.push(0);
    int  result =0 ;
    for (int i = 1; i < heights.size(); ++i) {
        if (heights[i]>=heights[my_stack.top()])
            my_stack.push(i);
        else
        {
            while (!my_stack.empty() and heights[i] < heights[my_stack.top()])
            {
                int mid = my_stack.top();
                my_stack.pop();
                int end=i;
                int start;
                if (!my_stack.empty())
                {
                    start = my_stack.top();
                    result = max(result, heights[mid] * (end - start-1));
                }
                else
                {
                    start = 0; // Ϊ�� ˵�����û�б�����С���� ��ô����Ϊ�߶ȵ�����ǿ���һ·������
                    result = max(result,heights[mid] * (end-start));
                }
            }
            my_stack.push(i);
        }
    }
    // ���Ǵ�ʱ����һЩԪ��û��pop
    return result;
}

int main()
{
    vector<int> heights = {2,3};
    cout<< largestRectangleArea(heights);
}