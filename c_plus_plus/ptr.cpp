/*
@File  :ptr.cpp
@Author:dfc
@Date  :2023/2/11  17:33
@Desc  : ÷∏’Îœ‡πÿ
*/
#include "iostream"
using namespace std;

int main()
{
    // int a = 5;
    // int *p = &a;
    // cout<<p<<endl;
    // cout<<&p;

    int *p3 = new int [3];
    p3[0] = 0;
    p3[1] = 1;
    p3[2] = 2;
    cout<<p3[0]<< " ";
    p3 = p3 +1;
    cout<<p3[0];
}

