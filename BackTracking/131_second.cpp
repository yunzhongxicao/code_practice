/*
@File  :131_second.cpp
@Author:dfc
@Date  :2023/3/9  10:13
@Desc  :
*/
#include "bits/stdc++.h"
using namespace std;

bool is_hui(string &s, int start, int end)
{
    while (start<=end)
    {
        if (s[start]==s[end])
        {
            start++;
            end--;
        }
        else return false;
    }
    return true;
}
vector<string> path ;
vector<vector<string>> result;

void backtracking(string &s, int start)
{
    if (start==s.size())
    {
        result.push_back(path);
        return;
    }
    for (int i = start; i < s.size(); ++i) {
        if (is_hui(s,start,i))
        {
            path.push_back(s.substr(start,i-start+1));
            backtracking(s,i+1);
            path.pop_back();
        }
    }

}

vector<vector<string>> partition(string s)
{
    backtracking(s,0);
    return result;
}

