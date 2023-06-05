/*
@File  :424.cpp
@Author:dfc
@Date  :2023/6/5  9:43
@Desc  :
*/
#include "iostream"
#include "string"
#include "vector"
using namespace std;

int characterReplacement(string s, int k)
{
    vector<int> char_vec(26,0);
    for (int i = 0; i < s.size(); ++i) {
        char_vec[s[i]-'A'] = 1;
    }
    int result = 0;
    for (int i = 0; i < char_vec.size(); ++i) {
        if (char_vec[i] == 0) continue;
        char target_char = 'A' + i;
        int left = 0, right = 0;
        int count = 0;
        int result_tmp = 0;
        while (right<= s.size()-1)
        {
            if (s[right] != target_char) count++;
            while (count>k)
            {
                if (s[left] != target_char) count--;
                left++;
            }
            result_tmp = max(result_tmp, right-left+1);
            right++;
        }
        result = max(result, result_tmp);
    }
    return result;
}
