/*
@File  :202_second.cpp
@Author:dfc
@Date  :2023/2/16  11:44
@Desc  : ¿ìÀÖÊı
*/
#include "iostream"
#include "vector"
#include "unordered_set"

using namespace std;

bool isHappy(int n)
{
    unordered_set<int> my_set;
    while (n!=1)
    {
        string n_s =  to_string(n);
        int  sum = 0;
        for (int i = 0; i < n_s.size(); ++i) {
            sum += (n_s[i]-'0') * (n_s[i]-'0');
        }
        if (my_set.find(sum) != my_set.end())
            return false;
        my_set.insert(sum);
        n =sum;
    }
    return true;
}

