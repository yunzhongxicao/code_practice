/*
@File  :offer_67.cpp
@Author:dfc
@Date  :2023/1/25  22:27
@Desc  : ���ַ���ת��������
*/
#include "vector"
#include "string"
#include "iostream"
#include "cmath"
using namespace std;

int strToInt(string str)
{
    if (str.empty()) return 0; // ���ַ���
    int first_index =0 ;
    while (first_index<=str.size()-1 and  str[first_index]==' ')
        first_index++;
    if (first_index==str.size() ) return 0; // ȫ�ǿհ��ַ�
    if (str[first_index]!='+' and str[first_index] !='-' and  (str[first_index]>'9' or str[first_index]<'0'))
        return 0;
    int flag=1;
    if (str[first_index]=='-')
    {
        flag = -1;
        first_index++;
    }
    else if (str[first_index]=='+')
    {
        flag=1;
        first_index++;
    }
    if (first_index==str.size()) return 0;// ����ֻ�������ŵ����
    int end_index = first_index;
    while (end_index<str.size() and (str[end_index]<='9' and str[end_index]>='0'))
        end_index++;
    // �ҵ�������
    while (first_index<end_index and str[first_index]=='0') // ȥ��ǰ��0
        first_index++;
    if (first_index==end_index) return 0; // end_index�����������
    string num_str = str.substr(first_index,end_index-first_index); // ��ʱ�����ᴿ�������ַ���
    if (num_str.size()>10 and flag==1) return INT32_MAX; // ������ȳ���10 ��ô��Ȼ����Խ����
    if (num_str.size()>10 and flag==-1 ) return INT32_MIN;
    long long result=0; // �ڳ���С��10 ������� ����longlong�������ʾ
    int j = 0; // �ƽ�λ����
    for (int i = num_str.size()-1; i >=0 ; --i) {
        result += (num_str[i]-'0') * pow(10,j);
        j++;
        if (result>=INT32_MAX and flag==1) return INT32_MAX;
        if (result>=(long long)INT32_MAX+1 and flag==-1) return INT32_MIN;
    }

    return flag * result;
}

