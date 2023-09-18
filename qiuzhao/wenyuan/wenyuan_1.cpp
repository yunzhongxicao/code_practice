/*
@File  :wenyuan_1.cpp
@Author:dfc
@Date  :2023/9/10  19:19
@Desc  :
*/
#include "iostream"
#include "string"

using namespace std ;

int main()
{
    string num="";
    char a;
    while (cin.get(a))
    {
        if (a=='\n')
        {
            break;
        }
        else
            num +=a;
    }
    string trans_num="";
    int end = 0;
    if (num[0]=='-') {
        trans_num.push_back('-');
        end = 1;
    }
    int start = num.size()-1;
    while (num[start]=='0')
        start--;
    while (start>=end)
    {
        trans_num.push_back(num[start]);
        start--;
    }
    long long result = stoll(trans_num);
    if (result>INT32_MAX or result < INT32_MIN) cout<<0<<endl;
    else cout<<result;
}