/*
@File  :7.cpp
@Author:dfc
@Date  :2023/3/5  13:48
@Desc  :
*/
#include "iostream"
using namespace std;

int main()
{
    int sum =0;
    int a;
    while (cin>>a)
    {
        sum += a;
        if (cin.get()=='\n') // 每次读完后再用get去读缓冲区的结束字符，不让cin清除
        {
            cout<<sum<<endl;
            sum=0;
        }
    }
}