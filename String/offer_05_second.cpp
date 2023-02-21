/*
@File  :offer_05_second.cpp
@Author:dfc
@Date  :2023/2/21  10:20
@Desc  : Ìæ»»¿Õ¸ñ
*/
#include "iostream"
#include "string"
using namespace std;

string replaceSpace(string s)
{
    int  count = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i]==' ') count++;
    }
    int old_index =s.size()-1;
    s.resize(s.size()+count*2);
    int new_index = s.size()-1;
    while (old_index>=0)
    {
        if (s[old_index]==' ')
        {
            s[new_index ]='0';
            new_index--;
            s[new_index]='2';
            new_index--;
            s[new_index]='%';

        }
        else
        {
            s[new_index] = s[old_index];
        }
        new_index--;
        old_index--;
    }
    return s;
}

