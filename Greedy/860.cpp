/*
@File  :860.cpp
@Author:dfc
@Date  :2022/10/31  11:13
@Desc  :ƒ˚√ ÀÆ’“¡„
*/

#include "vector"
#include "iostream"

using namespace std;

bool lemonadeChange(vector<int>& bills);

bool lemonadeChange(vector<int>& bills)
{
    int five=0, ten =0, twenty=0;
    for (int i = 0; i < bills.size(); ++i) {
        if (bills[i] ==5)  five++;
        else if (bills[i] ==10)
        {
            ten++;
            five--;
        }
        else if (bills[i] ==20)
        {
            if (ten>=1)
            {
                ten--;
                five--;
            }
            else
                five = five-3;
        }
        if (five<0 or ten<0) return false ;
    }
    return true;
}


