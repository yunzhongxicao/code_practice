/*
@File  :541.cpp
@Author:dfc
@Date  :2022/9/2  14:48
@Desc  :·´×ª×Ö·û´®
*/

#include "string"
#include "iostream"

using namespace std;

string reverseStr(string s, int k);
void reverse_substr(string &s,int start,int end);
int main()
{

}

string reverseStr(string s, int k)
{
    for (int i = 0; i < s.size(); i = i+2*k) {
        if (i+k<=s.size()-1)
        {
            reverse_substr(s,i,i+k-1);
            continue;
        }
        reverse_substr(s,i,s.size()-1);


    }
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
