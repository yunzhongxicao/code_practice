/*
@File  :offer_15.cpp
@Author:dfc
@Date  :2022/12/12  11:54
@Desc  : ��������1�ĸ���
*/
#include "iostream"
using namespace std;

/*int hammingWeight(uint32_t n) // ���ǲ��漰λ���� ֱ�Ӱ�ÿһλ������� ģ����һ����Ĺ���
{
    int mod=0;
    int count =0;
    while (n !=0)
    {
        mod = n % 2;
        if (mod==1) count++;
        n = n/2;
    }
    return count;
}*/

/*int hammingWeight(uint32_t n)// �������� ��ÿһλ��ȡ�������бȽ�
{
    int count= 0;
    for (int i = 0; i < 32; ++i) {
        count += ((n>>i) & 1); ��00001���������� ǰ�涼��0 ֻ�ÿ����һλ�ǲ���1 ��1�����Ϊ1 ֱ�Ӽ���ȥ ����1���Ϊ0 Ҳ���Լ���ȥ
    }
    return count;
}*/

int hammingWeight(uint32_t n) // �ȵ���λΪ0�ͽ���
{
    int count = 0;
    while (n !=0)
    {
        count += n&1;
        n = n>>1;
    }
    return count;

}


