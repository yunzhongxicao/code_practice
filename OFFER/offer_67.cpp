/*
@File  :offer_67.cpp
@Author:dfc
@Date  :2023/1/25  22:27
@Desc  : 把字符串转换成整数
*/
#include "vector"
#include "string"
#include "iostream"
#include "cmath"
using namespace std;

int strToInt(string str)
{
    if (str.empty()) return 0; // 空字符串
    int first_index =0 ;
    while (first_index<=str.size()-1 and  str[first_index]==' ')
        first_index++;
    if (first_index==str.size() ) return 0; // 全是空白字符
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
    if (first_index==str.size()) return 0;// 这是只有正负号的情况
    int end_index = first_index;
    while (end_index<str.size() and (str[end_index]<='9' and str[end_index]>='0'))
        end_index++;
    // 找到结束点
    while (first_index<end_index and str[first_index]=='0') // 去除前导0
        first_index++;
    if (first_index==end_index) return 0; // end_index是在数字外的
    string num_str = str.substr(first_index,end_index-first_index); // 此时才是提纯的数字字符串
    if (num_str.size()>10 and flag==1) return INT32_MAX; // 如果长度超过10 那么显然就是越界了
    if (num_str.size()>10 and flag==-1 ) return INT32_MIN;
    long long result=0; // 在长度小于10 的情况下 可用longlong来计算表示
    int j = 0; // 计进位的数
    for (int i = num_str.size()-1; i >=0 ; --i) {
        result += (num_str[i]-'0') * pow(10,j);
        j++;
        if (result>=INT32_MAX and flag==1) return INT32_MAX;
        if (result>=(long long)INT32_MAX+1 and flag==-1) return INT32_MIN;
    }

    return flag * result;
}

