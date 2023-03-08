/*
@File  :3.cpp
@Author:dfc
@Date  :2023/3/7  19:22
@Desc  :
*/

#include "iostream"
#include "cmath"
using namespace std;

int main()
{
    int  v, x, y;
    cin>>v>>x>>y;
     double x1 = x;
     double y1 = y;
     double v1 = v;
     double result = sqrt(4*y1/x1) - v1/x1;
     cout.precision(8);
     cout<<result;
}


