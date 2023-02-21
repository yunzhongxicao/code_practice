/*
@File  :offer_58_second.cpp
@Author:dfc
@Date  :2023/2/21  11:48
@Desc  : ×óÐý×ª×Ö·û´®
*/
#include "iostream"
#include "iostream"
using namespace std;

string reverseLeftWords(string s, int n)
{
    int end_index = s.size();
    s.resize(s.size()+n);
    int start_index = 0;
    while (end_index<=s.size()-1)
    {
        s[end_index] = s[start_index];
        start_index++;
        end_index++;
    }
    start_index =0 ;
    end_index = n;
    while (end_index<=s.size()-1)
    {
        s[start_index] = s[end_index];
        start_index++;
        end_index++;
    }
    s.resize(start_index);
    return s;
}

int main()
{
    string s  = "abcdefg";
    int k = 2;
    cout<<reverseLeftWords(s,k);
}


