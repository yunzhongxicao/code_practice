/*
@File  :383_second.cpp
@Author:dfc
@Date  :2023/2/15  14:34
@Desc  : Êê½ðÐÅ
*/
#include "iostream"
#include "string"
#include "vector"

using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    vector<int> r_count(26,0);
    vector<int> m_count(26,0);
    for(auto &i : ransomNote)
    {
        r_count[i-'a']++;
    }
    for(auto &j : magazine)
    {
        m_count[j-'a']++;
    }
    for (int i = 0; i < r_count.size(); ++i) {
        if (m_count[i] - r_count[i]<0   ) return false;
    }
    return true;
}

