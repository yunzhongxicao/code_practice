/*
@File  :3.cpp
@Author:dfc
@Date  :2023/3/23  19:03
@Desc  :
*/
#include "iostream"
#include "vector"
#include "string"

using namespace std;

int getCnt(string str)
{
    for (int i = 0; i < str.size(); ++i) {
        if (str[i]>='A' and str[i]<='Z')
            str[i] = str[i]-'A' +'a';
    }
    int start =0;
    int end;
    int result = 0;
    while (start<=str.size()-1){
        end = start;
        while (end<=str.size()-1 and  str[end]==str[start])
        {
            end++;
        }
        int length = end-start;
        int temp = length-1;
        result += temp;
        start = end;
    }
    return result;
}

int main()
{
    string s="aABbbc";
    // cin>>s;
    cout<<getCnt(s);
    // string s_trans(s.size(),'a');
    // for (int i = 0; i < s.size(); ++i) {
    //     if (s[i]>='A' and s[i]<='Z')
    //         s[i] = s[i]-'A' +'a';
    // }
    // cout<<s;
    // int start =0;
    // int end;
    // int result = 0;
    // for (int i = 0; i < s.size(); ++i) {
    //     end = start;
    //     while (end<=s.size()-1 and  s[end]==s[start])
    //     {
    //         end++;
    //     }
    //     int length = end-start;
    //     int temp = length-1;
    //     result += temp;
    // }
    // return result;
}

