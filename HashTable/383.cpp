/*
@File  :383.cpp
@Author:dfc
@Date  :2022/8/28  18:35
@Desc  : Êê½ðÐÅ
*/
#include "iostream"
#include "string"

using namespace std;

bool canConstruct(string ransomNote, string magazine);
int main()
{
    string s="aa",t = "aab";
    bool  result = canConstruct(s,t);
    cout<<result;
}

bool canConstruct(string ransomNote, string magazine)
{
    int record[26] = {0};
    for (int i = 0; i < ransomNote.size(); ++i) {
        int tmp = ransomNote[i] - 'a';
        record[tmp] ++;
    }
    for (int i = 0; i < magazine.size(); ++i) {
        int tmp = magazine[i] - 'a';
        record[tmp] --;
    }
    for (int i = 0; i < 26; ++i) {
        if (record[i] > 0)
        {
            return false;
        }
    }
    return true;
}