/*
@File  :93_second.cpp
@Author:dfc
@Date  :2023/3/16  10:34
@Desc  :
*/
#include "bits/stdc++.h"
using namespace std;

vector<string>path;
vector<string>result;

void backtracking(string &s, int start)
{
    if (path.size()==4 and start==s.size())
    {
        string temp;
        temp += path[0];
        for (int i = 1; i < 4; ++i) {
            temp += ("."+path[i]);
        }
        result.push_back(temp);
        return;
    }
    if (path.size()==4 and start<s.size())
        return;
    for (int i = start; i <s.size() ; ++i) {
        string temp= s.substr(start,i-start+1);
        if (s[start]=='0' and i>start) break;
        if (stoi(temp)>255)
            break;
        path.push_back(temp);
        backtracking(s,i+1);
        path.pop_back();
    }
}

vector<string> restoreIpAddresses(string s)
{
    backtracking(s,0);
    return result;
}

