/*
@File  :134.cpp
@Author:dfc
@Date  :2022/10/29  11:12
@Desc  :加油站
*/

#include "iostream"
#include "vector"

using namespace std;
/* 这是暴力解法 但是已经超时了
int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
    int gas_remain;
    int cur_position;
    int next_position;
    for (int i = 0; i < gas.size(); ++i) {
        gas_remain = gas[i] - cost[i]; // 算的是从本站出去还剩多少油 也就是到下一站不加油之前还剩多少油
        if (gas_remain<0) continue;

        int index = (i+1) % (int)gas.size(); // 环形遍历的写法

        while (gas_remain>=0 and index !=i)
        {
            gas_remain = gas_remain + gas[index] - cost[index]; // index和gas_remain是相互配合的 index是表示下一站要到的地方 remain是到那一站不加油之前还剩多少油
            index = (index+1) % (int)gas.size();
        }
        if (gas_remain>=0 and index==i ) return i; // 只有触发了第二个判断条件的 才说明到了起点

    }
    return -1;
}*/

int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
    int remain_all=0,remain_run=0,start=0;
    for (int i = 0; i < gas.size(); ++i) {
        remain_all += gas[i] - cost[i];
        remain_run += gas[i] - cost[i]; // 这里计算的是能不能从i走到i+1
        if (remain_run<0)
        {
            start= i+1; // 不用考虑越界 因为如果i=size-2 start=size-1; 如果i=size-1 依然还进了这个判断的话说明前面0->size-1都是负油耗 size-1->0 也是负数油耗 从油耗就判断了
            remain_run = 0;
        }
    }
    return remain_all>=0?start:-1;
}


