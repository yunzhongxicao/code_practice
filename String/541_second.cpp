/*
@File  :541_second.cpp
@Author:dfc
@Date  :2023/2/20  22:11
@Desc  : ·´×ª×Ö·û´®2
*/
#include "iostream"
#include "vector"
#include "string"
using namespace std;
void reverseString(string &s, int start ,int end)
{
    int left =start, right = end;
    while (left<right)
    {
        swap(s[left],s[right]);
        left++;
        right--;
    }
}

string reverseStr(string &s, int k)
{
    int count =0;
    while (count *k + k -1<=s.size()-1  )
    {
        if (count %2==0)
        {
            reverseString(s,count*k,count*k+k-1 );
        }
        count++;
    }
    if (count % 2==0 and count *k <=s.size()-1 )
    {
        reverseString(s,count*k,s.size()-1);
    }
    return s;
}

int main()
{
    string  s= "abcdefg";
    int k = 4;
    cout<<reverseStr(s,k);
}