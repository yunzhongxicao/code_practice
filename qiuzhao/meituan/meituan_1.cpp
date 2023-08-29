/*
@File  :meituan_1.cpp
@Author:dfc
@Date  :2023/8/26  10:02
@Desc  :
*/
#include "iostream"
#include "vector"

using namespace std;

int main()
{
    int x, y, z;
    cin>>x>>y>>z;
    int result = 0;
    int sum =0;
    while (sum<z)
    {
        sum +=1;
        if (result % 3 ==0)
            sum += 2;
        result++;
    }
    cout<<result;
}

