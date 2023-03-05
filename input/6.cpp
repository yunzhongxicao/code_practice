/*
@File  :6.cpp
@Author:dfc
@Date  :2023/3/5  13:41
@Desc  :
*/

#include "iostream"
using namespace std;

int main()
{
    int  n,a;

    while (cin>>n)
    {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            cin>>a;
            sum += a;
        }
        cout<<sum<<endl;

    }
}
