/*
@File  :3.cpp
@Author:dfc
@Date  :2023/3/5  13:32
@Desc  :
*/
#include "iostream"
using namespace std;

int main()
{
    int a,b;
    while (cin>>a>>b)
    {
        if (a==0 and b==0) break;
        cout<<a+b<<endl;
    }
}