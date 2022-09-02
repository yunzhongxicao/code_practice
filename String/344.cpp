/*
@File  :344.cpp
@Author:dfc
@Date  :2022/9/2  14:36
@Desc  :·´×ª×Ö·û´®
*/

#include "vector"
#include "iostream"

using namespace std;

void reverseString(vector<char>& s);

int main()
{

}

void reverseString(vector<char>& s)
{
    int left = 0;
    int right = s.size()-1;
    while (left<right)
    {
        swap(s[left],s[right]);
        left++;
        right--;
    }
}


