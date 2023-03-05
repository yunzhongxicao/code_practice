/*
@File  :4.cpp
@Author:dfc
@Date  :2023/3/5  13:36
@Desc  :
*/
#include "iostream"
using namespace std;

int main()
{
    int a;
    int t   ;
    while (cin>>t)
    {
        if (t==0) break;
        int sum =0;
        for (int i = 0; i <t ; ++i) {
            cin>>a;
            sum += a;
        }
        cout<<sum<<endl;
    }
}