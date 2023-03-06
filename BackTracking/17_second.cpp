/*
@File  :17_second.cpp
@Author:dfc
@Date  :2023/3/6  14:39
@Desc  : 电话号码的字母组合
*/
#include "iostream"
#include "vector"
#include "string"

using namespace std;

vector<string> v_str={
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
};
string path;
vector<string> result;

void backtracking(int start, const string &digits)
{
    if (path.size()==digits.size())
    {
        result.push_back(path);
        return;
    }
    string temp = v_str[digits[start]-'0'];
    for (int i = 0; i < temp.size(); ++i) {
        path += temp[i];
        backtracking(start+1,digits);
        path.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    if (digits.size()==0) return result;
    backtracking(0,digits);
    return result;
}


