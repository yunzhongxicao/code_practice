/*
@File  :offer_11.cpp
@Author:dfc
@Date  :2022/12/6  10:53
@Desc  : Ѱ����ת�����е���С����
*/
#include "iostream"
#include "vector"
using namespace std;
int minArray(vector<int>& numbers)
{
    int result = numbers[0];  // �ҵ��뷨�� ǰһ�ε��� ��һ�ε���  ��ôֻҪ�ҵ���һ�������½��ĵ� ������ת����
    for (int i = 1; i < numbers.size(); ++i) {
        if (numbers[i]<numbers[i-1])
        {
            result = numbers[i];
            break;
        }
    }
    return result;
}

