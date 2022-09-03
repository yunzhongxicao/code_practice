/*
@File  :28.cpp
@Author:dfc
@Date  :2022/9/2  19:43
@Desc  :й╣ож strStr()
*/
#include "iostream"
#include "string"


using namespace std;

int strStr(string haystack, string needle);
void getNext(int* next, const string& s);

int main()
{
    int *a;
    string s = "abaafabab";
    getNext(a,s);
    for (int i = 0; i < s.size(); ++i) {
        cout<<a[i]<<" ";
    }
    string hay = "hello";
    string nee = "ll";
    int b = strStr(hay,nee);
    cout<<endl;
    cout<<b;


}

int strStr(string haystack, string needle)
{
    int next[needle.size()];
    getNext(next,needle);
    int j = 0;
    for (int i = 0; i < haystack.size();i++ )
    {

        while (j>0 and needle[j] != haystack[i] )
        {
            j = next[j-1];
        }
        if (haystack[i] == needle[j])
        {
            j++;
        }
        if (j == needle.size())
        {
            return i-needle.size()+1;
        }
    }
        return -1;
}

void getNext(int* next, const string& s) {
    int j = 0;
    next[0] = 0;
    for (int i = 1; i < s.size(); ++i) {

        while (j>0 and s[i] != s[j])
        {
            j = next[j-1];
        }
        if (s[i] == s[j])
        {
            j++;
        }
        next[i] = j;

    }
}