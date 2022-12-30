/*
@File  :offer_43.cpp
@Author:dfc
@Date  :2022/12/30  10:06
@Desc  :1-n整数中出现1的次数
*/
#include "string"
#include "iostream"
#include "cmath"
using namespace std;
int countDigitOne(int n)
{
    string n_s = to_string(n);
    int result = 0;
    for (int i = 0; i <= n_s.size()-1; ++i) {
        int pre_length = i;
        int last_length = n_s.size()-1-i;
        string  pre,last;
        if (pre_length==0)
            pre="0";
        else pre = n_s.substr(0,pre_length);
        if (last_length==0)
            last = "0";
        else last = n_s.substr(i+1,last_length);
        int tmp1 = (stoi(pre)-0) * pow(10,last_length);
        int tmp2;
        if (n_s[i]>'1') tmp2 = pow(10,last_length);
        else if (n_s[i]=='1') tmp2 = stoi(last)+1;
        else tmp2=0;
        result += tmp1+tmp2;
    }
    return result;
}

int main()
{
    cout<<countDigitOne(808182);
}
