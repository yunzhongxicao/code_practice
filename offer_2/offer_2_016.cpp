/*
@File  :offer_2_016.cpp
@Author:dfc
@Date  :2023/2/23  11:38
@Desc  : 不含重复字符的最长子字符串
*/
#include "iostream"
#include "string"
#include "vector"

using namespace std;

int lengthOfLongestSubstring(string s)
{
    if (s.empty()) return 0;
    int last_length=1;
    int result = 1;
    for (int i = 1; i < s.length(); ++i) {
        int length ;
        if (s[i] ==s[i-1]) length=1;
        else
        {
            int start = i-1;
            while (start>=i-last_length and s[start] != s[i])
            {
                start--;
            }
            length = i-start;
        }
        last_length =length;
        result = max(result,length);
    }
    return result;
}

