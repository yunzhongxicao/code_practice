/*
@File  :134.cpp
@Author:dfc
@Date  :2022/10/29  11:12
@Desc  :╪ссму╬
*/

#include "iostream"
#include "vector"

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
    int gas_remain;
    int cur_position;
    int next_position;
    for (int i = 0; i < gas.size(); ++i) {
        gas_remain = cost[i] - gas[i];
        if (gas_remain<0) continue;
        cur_position = i;
        while (gas_remain>=0 and cur_position!=i)
        {
            if (cur_position==gas.size()-1)
                next_position= 0;
            else next_position= cur_position+1;
            gas_remain = gas_remain + cost[next_position] - gas[next_position];
            cur_position = next_position;
        }

    }
}


