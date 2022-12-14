/*
@File  :offer_20.cpp
@Author:dfc
@Date  :2022/12/14  17:49
@Desc  : 表示数值的字符串
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
    if (start>end) return false; // 找到不包含空格的首尾位置,其实这句话不需要，因为结尾肯定此时不是数字结尾
    for (int i = start; i <=end; ++i) {
        if (s[i]=='+' or s[i]=='-') // 正负号可以重复使用 但是只能在第一个位置或者eE后面，其实也就说明最多使用两次
        {
            if (i!=start and s[i-1]!='e' and s[i-1]!='E') return false;
        }
        else if (s[i]=='e' or s[i]=='E')
        {
            if (is_eE) return false;  // 小数点的判断留到后面小数点的情况
            if (!is_num) return false; // eE 不能重复出现
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
    return is_num; // 结尾必须以数字结尾
}