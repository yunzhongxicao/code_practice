/*
@File  :242.cpp
@Author:dfc
@Date  :2022/8/28  18:07
@Desc  : 有效的字母异位词
*/
#include "iostream"
#include "string"

using namespace std;

bool isAnagram(string s, string t);

int  main()
{
    string s =  "anagram";
    string t =  "nagaram";
    bool result = isAnagram(s,t);
    cout<<result;
}

bool isAnagram(string s, string t)
{
    int record[26] = {0};
    for (int i = 0; i < s.size(); ++i) {
        int tmp = s[i] - 'a';
        record[tmp] ++;
    }
    for (int i = 0; i < t.size(); ++i) {
        int tmp = t[i] - 'a';
        record[tmp] --;
    }
    for (int i = 0; i < 26; ++i) {
        if (record[i] != 0)
        {
            return false;
        }
    }
    return true;
}