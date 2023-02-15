/*
@File  :242_second.cpp
@Author:dfc
@Date  :2023/2/15  14:27
@Desc  : 有效的字母异位词
*/
#include "iostream"
#include "string"
#include "vector"

using namespace std;

bool isAnagram(string s, string t)
{
    vector<int>s_count(26,0);
    vector<int>t_count(26,0);
    for(auto &i :s)
    {
        s_count[i-'a']++;
    }
    for(auto &j :  t)
    {
        t_count[j-'a']++;
    }
    for (int i = 0; i < 26; ++i) {
        if (s_count[i] != t_count[i]) return false;
    }
    return true;
}

