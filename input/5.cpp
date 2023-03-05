/*
@File  :5.cpp
@Author:dfc
@Date  :2023/3/5  13:38
@Desc  :
*/
#include "iostream"
using namespace std;

int main()
{
    int t, n,a;
    cin>>t;
    while (t>0)
    {
        cin>>n;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            cin>>a;
            sum += a;
        }
        cout<<sum<<endl;
        t--;
    }
}