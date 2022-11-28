/*
@File  :503.cpp
@Author:dfc
@Date  :2022/11/28  11:02
@Desc  : ��һ������Ԫ��2
*/
#include "vector"
#include "iostream"
#include "stack"

using namespace std;

vector<int> nextGreaterElements(vector<int>& nums)
{
    vector<int> nums2;
    nums2.insert(nums2.end(),nums.begin(),nums.end());
    nums2.insert(nums2.end(),nums.begin(),nums.end());
    vector<int> result(nums.size(),-1);
    stack<int> my_stack;

    for (int i = 0; i < nums2.size(); ++i) {
        while  (!my_stack.empty() and nums2[i]>nums2[my_stack.top()])
        {
            // ��������Ԫ�� ����ֵҪ��ԭʼ�ķ�Χ�� ��Ϊ����ֻ��עǰ����һ��
            // ʹ�õ�����Ԫ��Ҫ��������Χ�� ��һ�����ȵ�������Χ
            if (my_stack.top()<=nums.size()-1 and i<=my_stack.top()+nums.size()-1)
            {
                result[my_stack.top()] = nums2[i];
            }
            my_stack.pop();
        }
        my_stack.push(i);
    }
    return result;
}

int main()
{
    vector<int> nums = {1,2,1};
    vector<int> result = nextGreaterElements(nums);
    for (int i = 0; i < result.size(); ++i) {
        cout<<result[i]<<" ";
    }
}