/*
@File  :131_third.cpp
@Author:dfc
@Date  :2023/7/18  21:51
@Desc  :
*/
#include "iostream"
#include "vector"
#include "string"

using namespace std;

bool is_valid(const string &s, int start ,int end)
{
    while (start<=end)
    {
        if (s[start] == s[end])
        {
            start++;
            end--;
        } else return false;
    }
    return true;
}

vector<string>path;
vector<vector<string>> result;

void backtracking(int start, string s)
{
    if (start==s.size())
    {
        result.push_back(path);
        return;
    }
    for (int i = start; i <=s.size()-1 ; ++i) {
        if (is_valid(s,start,i))
        {
            path.push_back(s.substr(start,i-start+1));
            backtracking(i+1,s);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    backtracking(0,s);
    return result;
}

