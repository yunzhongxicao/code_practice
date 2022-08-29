/*
@File  :438.cpp
@Author:dfc
@Date  :2022/8/29  13:26
@Desc  :找到字符串中所有字母异位词
*/

#include "map"
#include "string"
#include "iostream"
#include "vector"
#include <algorithm>

using namespace std;

vector<int> findAnagrams_1(string s, string p);
vector<int> findAnagrams_2(string s, string p);

int main()
{
    string s(3e4,'a');
    string p(2e4,'a');
    vector<int> a = findAnagrams_2(s,p);
    for (int i = 0; i < a.size(); ++i) {
        cout<<a[i]<<" ";
    }

}

vector<int> findAnagrams_1(string s, string p)  // 这种方法超时了
{
    int p_length = p.length();
    int s_length = s.length();
    string p_sort = p;
    sort(p_sort.begin(),p_sort.end());
    vector<int > result={};
    for (int i = 0; i <= s_length - p_length; ++i) {  //这里要注意的是 size()的返回值是unsigned long 所以没法表示负数
        string tmp = s.substr(i,p_length);
        sort(tmp.begin(),tmp.end());
        if (tmp==p_sort)
            result.push_back(i);
    }
    return result;
}

vector<int> findAnagrams_2(string s, string p)
{
    if (s.length()<p.length())
        return {};
    vector<int>s_count(26,0);
    vector<int>p_count(26,0);
    vector<int> result;

    for (int i = 0; i < p.size(); ++i) {
        s_count[s[i]-'a']++;
        p_count[p[i]-'a']++;
    }
    if (s_count==p_count)
        result.push_back(0);
    for (int i = 1; i <= s.length()-p.length(); ++i) {
        s_count[s[i-1]-'a']--;
        s_count[s[i+p.length()-1]-'a']++;
        if (s_count==p_count)
            result.push_back(i);
    }
    return result;
}