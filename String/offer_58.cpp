/*
@File  :offer_58.cpp
@Author:dfc
@Date  :2022/9/2  17:30
@Desc  :×óÐý×ª×Ö·û´®
*/
#include "vector"
#include "string"
#include "iostream"
using namespace std;

string reverseLeftWords(string s, int n);
void reverse_substr(string &s,int start,int end);
int main()
{
    string s = "abcdefg";
    int k =2;
    string b = reverseLeftWords(s,k);
    cout<<b;
}
string reverseLeftWords(string s, int n)
{
    reverse_substr(s,0,s.size()-1)  ;
    reverse_substr(s,0,s.size()-n-1);
    reverse_substr(s,s.size()-n,s.size()-1);
    return s;
}
void reverse_substr(string &s,int start,int end)
{
    while (start<end)
    {
        swap(s[start],s[end]);
        start++;
        end--;
    }
}