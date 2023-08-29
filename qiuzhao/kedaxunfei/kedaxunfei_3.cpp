/*
@File  :kedaxunfei_3.cpp
@Author:dfc
@Date  :2023/7/22  19:46
@Desc  :
*/
#include "iostream"
#include "string"
#include "vector"

using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;
    if (k>n/2)
    {
        cout<<-1;
        return 0;
    }
    string result(n,'z');
    if (k==1)
    {
        result[0] = 'a';
        cout<<result;
        return 0;
    }
    if (k==2)
    {
        result[0]='a';
        result[1]='c';
        // result[2]='a';
        cout<<result;
        return 0;
    }
    if (k==3)
    {
        result[0] = 'a';
        result[2] = 'a';
        result[1] = 'c';
        result[3] = 'd';
        cout<<result;
        return 0;
    }
}

