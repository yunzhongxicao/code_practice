/*
@File  :438_second.cpp
@Author:dfc
@Date  :2023/2/15  15:08
@Desc  : 找到字符串中所有字母异位词
*/
#include "iostream"
#include "vector"
#include "string"

using namespace std;
vector<int> findAnagrams(string s, string p)
{
    string s_p(26,'0');
    string s_s(26,'0');
    vector<int> result;
    if (s.size()<p.size()) return result;
    for (int i = 0; i < p.size(); ++i) {
        s_p[p[i]-'a']++;
    }
    for (int i = 0; i < p.size(); ++i) {
        s_s[s[i]-'a']++;
    }
    if (s_s==s_p) result.push_back(0);
    for (int i = 1; i+p.size()-1 <=s.size()-1 ; ++i) {
        s_s[s[i-1]-'a']--;
        s_s[s[i+p.size()-1]-'a']++;
        if (s_s==s_p)
            result.push_back(i);
    }
    return result;
}

int main()
{
    string s = "abab", p = "ab";
    vector<int>  result =  findAnagrams(s,p);
    for (int i = 0; i < result.size(); ++i) {
        cout<<result[i]<<" ";
    }
}
