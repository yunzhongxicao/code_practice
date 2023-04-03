/*
@File  :offer_2_019.cpp
@Author:dfc
@Date  :2023/4/3  11:43
@Desc  :
*/
#include "iostream"
#include "vector"
#include "string"
using namespace std;

bool check(string &s, int start, int end)
{
    while (start<=end)
    {
        if (s[start] == s[end])
        {
            start++;
            end--;
        }
        else
            return false;
    }
    return true;
}

bool validPalindrome(string s)
{
    int start = 0, end = s.size()-1;
    int count = 0;
    while (start<=end)
    {
        if (s[start]==s[end])
        {
            start++;
            end--;
        }
        else
            return check(s,start+1,end) or check(s,start,end-1);
    }
    return true;
}

/*bool validPalindrome(string s)
{
    int start = 0, end = s.size()-1;
    int count = 0;
    while (start<=end)
    {
        if (s[start]==s[end])
        {
            start++;
            end--;
        }
        else if (s[start+1]==s[end])
        {
            start++;
            count++;
        }
        else if (s[end-1]==s[start])
        {
            end--;
            count++;
        }
        else return false;
        if (count==2) return false;
    }
    return true;
}*/

int main()
{
    string s = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";
    // string s = "ffcnqxjjxqncff";
    cout<<validPalindrome(s);
}
