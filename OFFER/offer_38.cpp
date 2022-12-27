/*
@File  :offer_38.cpp
@Author:dfc
@Date  :2022/12/27  13:57
@Desc  :
*/
#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
using namespace std;
void backtracking(string &s, vector<int> &used);
string path="";
vector<string> result;
vector<string> permutation(string s)
{
    sort(s.begin(),s.end());
    vector<int> used(s.size(),0);
    backtracking(s,used);
    return result;
}

void backtracking(string &s, vector<int> &used)
{
    if (path.size()==s.size()) {
        result.push_back(path);
        return;
    }
    for (int i = 0; i < s.size(); ++i) {
        if (used[i]==1)
            continue;
        if (i>=1 and s[i]==s[i-1] and used[i-1]==0)
            continue;
        path +=s[i] ;
        used[i] = 1;
        backtracking(s,used);
        path.pop_back();
        used[i] = 0;
    }
}