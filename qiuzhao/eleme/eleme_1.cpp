/*
@File  :eleme_1.cpp
@Author:dfc
@Date  :2023/8/29  10:22
@Desc  :
*/
#include "iostream"
#include "vector"
#include "string"
#include "unordered_set"

using namespace std;

int main()
{
    string s;
    cin>>s;
    unordered_set<char> yuanyin_set;
    yuanyin_set.insert('a'); yuanyin_set.insert('o'); yuanyin_set.insert('e'); yuanyin_set.insert('i'); yuanyin_set.insert('u');
    if (s.size()<5)
    {
        cout<<0<<endl;
        return 0;
    }
    int end = 4;
    int result = 0;
    while (end<=s.size()-1)
    {
        if (s[end]== s[end-2] and  s[end-2] == s[end-4]
            and yuanyin_set.find(s[end])!= yuanyin_set.end()
            and s[end-1] != s[end-3]
            and yuanyin_set.find(s[end-1])== yuanyin_set.end()
            and yuanyin_set.find(s[end-3]) == yuanyin_set.end())
        {
            result++;
            end++;
        }
        else
        {
            end++;
        }
    }
    cout<<result<<endl;
}

