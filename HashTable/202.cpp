/*
@File  :202.cpp
@Author:dfc
@Date  :2022/8/30  11:42
@Desc  : ¿ìÀÖÊı
*/
#include "map"
#include "string"
#include "iostream"
#include "vector"
#include "unordered_set"
#include "unordered_map"
#include <algorithm>

using namespace std;

int get_sum(int n);
bool isHappy(int n);

int main()
{
    int a = get_sum(19);
    cout<<a;
}

int get_sum(int n)
{
    int sum=0;
    while (n>0)
    {
        int tmp = n%10;
        sum = sum + tmp * tmp;
        n = n/10;
    }
    return sum;
}

bool isHappy(int n)
{
    unordered_set<int>my_set;
    while (n!=1)
    {
        n = get_sum(n);
        auto rec = my_set.insert(n);
        if (!rec.second)
            return false;
    }
    return true;
}

