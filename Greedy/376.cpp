/*
@File  :376.cpp
@Author:dfc
@Date  :2022/10/27  11:37
@Desc  : �ڶ�����
*/


#include "iostream"
#include "vector"
#include "string"

using namespace std;

int wiggleMaxLength(vector<int>& nums)
{
    int pre_diff =0; // ֻ�����ʼ��ʱ�� ����0���൱��-1�ĵط�����һ��nums[0]
    int cur_diff =0;
    int result= 0;
    for (int i = 1; i < nums.size(); ++i) { // iҪ��1��ʼ ��¼i-1��i����ת�۵�
        cur_diff= nums[i] - nums[i-1];
        if ((cur_diff>0 and pre_diff<=0) or (cur_diff<0 and pre_diff>=0)) // ���0ֻ�����ʼ��ʱ�����֣�����curֻ���ڲ�Ϊ0��ʱ��Żḳֵ��pre
        {
            result++;   // Ҫ�ر�ע����� ��ʱ���¼��ת�۵���ʵ��i-1
            pre_diff= cur_diff;
        }
    }
    result++; // ��Ϊ���һ����һ����ת�۵� ��Ϊ�м�ɾ��Ҳ��ֻȡ�˵���������� �������һ����һ��Ҫȡ��
    return result;
}