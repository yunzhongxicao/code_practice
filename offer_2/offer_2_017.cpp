/*
@File  :offer_2_017.cpp
@Author:dfc
@Date  :2023/4/1  23:03
@Desc  :
*/
#include "iostream"
#include "unordered_map"
#include "string"
#include "vector"
using namespace std;
unordered_map<char,int> ori, new_map;

bool check()
{
    for(auto &iter:ori)
    {
        if (new_map[iter.first]<iter.second)
            return false;
    }
    return true;
}

string minWindow(string s, string t)
{
    for (int i = 0; i < t.size(); ++i) {
        ori[t[i]]++;
    }
    int start = 0;
    int end = start;
    vector<int>start_to_end(2,0); // ÆðÊ¼  ½áÊø
    int length = INT32_MAX;
    while (end<s.size())
    {
        if(ori.find(s[end]) != ori.end())
            new_map[s[end]]++;
        while (check())
        {
            if (end-start+1<length)
            {
                start_to_end[0] = start;
                start_to_end[1] = end;
                length = end-start+1;
            }
            if (ori.find(s[start]) != ori.end())
                new_map[s[start]]--;
            start++;

        }
        end++;
    }
    string result;
    if (length==INT32_MAX) return result;
    for (int i = start_to_end[0]; i <=start_to_end[1] ; ++i) {
        result += s[i];
    }
    return result;
}

int main()
{
    string s = "a", t = "a";
    cout<<minWindow(s,t);
}
