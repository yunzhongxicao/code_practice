/*
@File  :45.cpp
@Author:dfc
@Date  :2022/10/28  11:56
@Desc  : ��Ծ��Ϸ2
*/

#include "iostream"
#include "vector"

using namespace std;

int jump(vector<int>& nums)
{
    int cur_jump= 0; // ��ǰ��������Զ����
    int next_jump = 0; // ��һ������������Զ����

    int result=0 ;
    for (int i = 0; i < nums.size(); ++i) {
        // ����һ�����Ĺ����м�¼��һ��������Զ���� �����һ����û���յ㣬 ��ô��һ�����;͵���������м�¼����Զ����
        next_jump = max(i+nums[i],next_jump);
        if (i==cur_jump) // �ﵽ��һ���������յ�
        {
            if (cur_jump<nums.size()-1)
            {
                result++; // ��Ҫ�ٴ�����
                cur_jump = next_jump; // ��һ����������Զ����
                if (next_jump>=nums.size()-1) break; //  �����һ����������Զ���뵽�յ��ˣ���ֱ�ӽ��������������Լ����ȥ��
            }
            else break;
        }
    }
    return result;
}


