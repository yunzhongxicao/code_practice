/*
@File  :offer_65.cpp
@Author:dfc
@Date  :2023/1/17  20:10
@Desc  : ���üӼ��˳����ӷ�
*/
#include "iostream"
using namespace std;

int add(int a, int b)
{
    while (b!=0)
    {
        int temp1 = a^b;
        //LC c++��֧�ָ�ֵ���ƣ���Ҫǿ��ת��Ϊ�޷�����
        int temp2 = (unsigned int )(a&b)<<1;// ���� ������ ���32�ξ�Ϊ0
        a = temp1;
        b = temp2;
    }
    return a;

}

