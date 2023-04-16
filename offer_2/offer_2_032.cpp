/*
@File  :offer_2_032.cpp
@Author:dfc
@Date  :2023/4/16  16:06
@Desc  :
*/
#include "iostream"
#include "string"
#include "vector"

using  namespace std;

bool isAnagram(string s, string t)
{
    if (s.size() != t.size()) return false;
    vector<int> nums(26,0);
    for (int i = 0; i < s.size(); ++i) {
        nums[s[i]-'a']++;
    }
    for (int i = 0; i < t.size(); ++i) {
        nums[t[i]-'a']--;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != 0) return false;
    }
    for (int i = 0; i < s.size(); ++i) {
        if (s[i]!=t[i]) return true;
    }
    return false;
}

