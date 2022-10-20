/*
@File  :131.cpp
@Author:dfc
@Date  :2022/10/20  10:08
@Desc  : 分割回文串
*/

#include "vector"
#include "iostream"
#include "string"

using namespace std;

bool isPalindrome(const string& s)
{
    for (int i = 0,j=s.size()-1; i < j; ++i,--j) {
        if (s[i] != s[j])return false;
    }
    return true;
}

vector<string> path;
vector<vector<string>>  result;
void backtracking(int start_index,string s) // start_index表示切割的起始点
{
    if (start_index==s.size())
    {
        result.push_back(path);
        return;
    }

    for (int i = start_index; i < s.size()  ; ++i) {
        string s_sub = s.substr(start_index,i-start_index+1); // i表示切割的结束点
        bool flag = isPalindrome(s_sub);
        if (!flag) continue;
        path.push_back(s_sub);
        backtracking(i+1,s);
        path.pop_back();
    }
}

vector<vector<string>> partition(string s)
{
    backtracking(0,s);
    return result;
}

int main()
{
    string s = "a";
    partition(s);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}