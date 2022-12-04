/*
@File  :offer_05.cpp
@Author:dfc
@Date  :2022/12/4  21:18
@Desc  : 替换空格
*/
#include "iostream"
#include "vector"
#include "string"

using namespace std;

/*string replaceSpace(string s)  // 这是最直观的做法
{
    string new_s(s.size()*3,' '); // 这样申请其实是有浪费空间的
    int new_index =0 ;
    for (int i = 0; i < s.size(); ++i) {  // 从前往后遍历 就势必要新申请数组
        if (s[i]!=' ')
        {
            new_s[new_index] = s[i];
            new_index++;
        }
        else
        {
            new_s[new_index] = '%';
            new_s[new_index+1] = '2';
            new_s[new_index+2] = '0';
            new_index  += 3;
        }
    }
    new_s.resize(new_index);
    return new_s;
}*/


string replaceSpace(string s)
{
    int count = 0; // 先计算空格的数量 这样新申请的空间就不会浪费
    for (char i : s) {
        if (i==' ') count++;
    }
    int old_index= s.size()-1;
    s.resize(s.size()+count*2);
    int new_index = s.size()-1;
    while (old_index>=0)
    {
        if (s[old_index] != ' ')
        {
            s[new_index] = s[old_index];
            new_index--;
        }
        else
        {
            s[new_index] = '0';
            new_index--;
            s[new_index] = '2';
            new_index--;
            s[new_index]= '%';
            new_index--;
        }
        old_index--;
    }
    return s;
}

