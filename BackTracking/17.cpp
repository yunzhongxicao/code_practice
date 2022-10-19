/*
@File  :17.cpp
@Author:dfc
@Date  :2022/10/19  11:58
@Desc  : 电话号码的字母组合
*/

#include "string"
#include "iostream"
#include "vector"
using namespace std;

const string letter_map[10]={
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

vector<string> letterCombinations(string digits);
void backtracking(string digits, int start_index);

void backtracking(string digits, int start_index)
{
    char num_char = digits[start_index];
    int num = num_char-'0'; // 如何将char转化为数字
    if (path.size()==digits.size())
    {
        result.push_back(path);
        return;
    }
    string letter = letter_map[num];
    for (int i = 0; i < letter.size(); ++i) {
        path+=letter[i];
        backtracking(digits,start_index+1);
        path.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    if(digits.size()==0) return result;
    backtracking(digits,0);
    return result;
}

int main()
{
    letterCombinations("23");
    for (int i = 0; i < result.size(); ++i) {
        cout<<result[i]<<endl;
    }
}


