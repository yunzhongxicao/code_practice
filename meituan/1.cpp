/*
@File  :1.cpp
@Author:dfc
@Date  :2023/3/11  19:06
@Desc  :
*/
#include "bits/stdc++.h"
using namespace std;

int main()
{
    string s;
    cin>>s;
    int result = 0;
    int start = 0;
    int end =0;
    while (end<=s.size()-1)
    {
        start = end;
        while (end<=s.size()-1 and  s[start]==s[end])
        {
            end++;
        }
        int length = end-start;
        result += length/2;
    }
    cout<<result;
    return 0;
}

