/*
@File  :offer_2_014.cpp
@Author:dfc
@Date  :2023/2/22  10:33
@Desc  : 字符串中的变位词
*/
#include "iostream"
#include "vector"
#include "string"

using namespace std;

bool checkInclusion(string s1, string s2)
{
    vector<int>count_1(26,0),count_2(26,0);
    for (int i = 0; i < s1.size(); ++i) {
        count_1[s1[i]-'a']++;
    }
    if (s2.size()<s1.size()) return false;
    for (int i = 0; i < s1.size(); ++i) {
        count_2[s2[i]-'a']++;
    }
    if (count_2==count_1) return true;
    for (int i = 1; i+s1.size()-1<=s2.size()-1; ++i) {
        count_2[s2[i-1]-'a']--;
        count_2[s2[i+s1.size()-1]-'a']++;
        if (count_2== count_1) return true;
    }
    return false;
}

