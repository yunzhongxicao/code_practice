/*
@File  :offer_2_018.cpp
@Author:dfc
@Date  :2023/4/3  11:26
@Desc  :
*/
#include "iostream"
#include "vector"
#include "string"
using namespace std;

char change(char ch)
{
    if (ch>='A' and ch <='Z')
        ch = ch-'A' + 'a';
    else if (ch>='a' and ch<='z')
        ch = ch;
    else if (ch>='0' and ch<='9')
        ch =ch;
    else
        ch = '.';
    return ch;
}

bool isPalindrome(string s)
{
    int start = 0;
    int end = s.size()-1;
    while (start<=end)
    {
        char temp1 = s[start];
        char temp2 =s[end];
        temp1 = change(temp1);
        temp2  = change(temp2);
        if (temp1=='.')
        {
            start++;
            continue;
        }
        if (temp2=='.')
        {
            end--;
            continue;
        }
        if (temp1==temp2)
        {
            start++;
            end--;
        }
        else return false;
    }
    return true;
}

