/*
@File  :offer_50.cpp
@Author:dfc
@Date  :2023/1/2  14:57
@Desc  :第一个只出现一次的字符
*/
#include "iostream"
#include "string"
#include "unordered_map"
using namespace std;

char firstUniqChar(string s)
{
    if (s.size()==0) return ' ';
    unordered_map<char,int> my_map;
    for (int i = 0; i < s.size(); ++i) {
        my_map[s[i]]++;
    }
    for(int i=0;i<s.size();++i) // 直接遍历字符串即可
    {
        if (my_map[s[i]]==1) return s[i];
    }
    return ' ';
}

int main()
{
    string s = "leetcode";
    cout<<firstUniqChar(s);
}

