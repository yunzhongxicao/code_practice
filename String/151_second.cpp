/*
@File  :151_second.cpp
@Author:dfc
@Date  :2023/2/21  10:39
@Desc  : 反转字符串的单词
*/
#include "iostream"
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

string reverseWords(string s)
{
    int slow_index = 0,fast_index =  0;
    while (s[fast_index]==' ')
        fast_index++;
    while (fast_index<=s.size()-1)
    {
        if (s[fast_index]== ' ' and s[fast_index]==s[fast_index-1])
            fast_index++;
        else
        {
            s[slow_index] = s[fast_index];
            fast_index++;
            slow_index++;
        }
    }
    if (s[slow_index-1] == ' ') // 此时slow_index跳出来的时候加1了 所以最后一个复制的应该是-1
        slow_index--;
    s.resize(slow_index); // 此时slow_index在最后一个复制的外面  这里不用substr 直接resize节省空间


    reverseString(s,0,s.size()-1);
    int left = 0,right =0;
    while (left<=s.size()-1 )
    {
        right =left;
        while (right<=s.size()-1 and s[right]!=' ')
            right++;
        reverseString(s,left,right-1);
        left = right+1;
    }
    return s;
}


int main()
{
    string s = "  hello world  ";
    cout<<reverseWords(s);
}
