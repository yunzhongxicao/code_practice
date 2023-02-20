/*
@File  :344_second.cpp
@Author:dfc
@Date  :2023/2/20  22:05
@Desc  : ·´×ª×Ö·û´®
*/
#include "vector"
#include "iostream"
using namespace std;

void reverseString(vector<char>& s)
{
    int left =0, right = s.size()-1;
    while (left<right)
    {
        swap(s[left],s[right]);
        left++;
        right--;
    }
}

