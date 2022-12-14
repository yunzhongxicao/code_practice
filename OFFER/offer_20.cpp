/*
@File  :offer_20.cpp
@Author:dfc
@Date  :2022/12/14  17:49
@Desc  : ��ʾ��ֵ���ַ���
*/
#include "iostream"
#include "string"
using namespace std;

bool isNumber(string s)
{
    bool is_eE= false,is_dot= false,is_num= false;
    int start=0;
    if (s.size()==0) return false;
    while (start<=s.size()-1 and s[start]==' ')
    {
        start++;
    }
    int end=s.size()-1;
    while (end>=0 and s[end]==' ')
    {
        end--;
    }
    if (start>end) return false; // �ҵ��������ո����βλ��,��ʵ��仰����Ҫ����Ϊ��β�϶���ʱ�������ֽ�β
    for (int i = start; i <=end; ++i) {
        if (s[i]=='+' or s[i]=='-') // �����ſ����ظ�ʹ�� ����ֻ���ڵ�һ��λ�û���eE���棬��ʵҲ��˵�����ʹ������
        {
            if (i!=start and s[i-1]!='e' and s[i-1]!='E') return false;
        }
        else if (s[i]=='e' or s[i]=='E')
        {
            if (is_eE) return false;  // С������ж���������С��������
            if (!is_num) return false; // eE �����ظ�����
            is_eE = true;
            is_num= false;
        }
        else if (s[i]>='0' and s[i]<='9')
            is_num= true;
        else if (s[i]=='.')
        {
            if (is_dot or is_eE) return false;
            else
            {
                is_dot = true;
            }
        }
        else return false;

    }
    return is_num; // ��β���������ֽ�β
}