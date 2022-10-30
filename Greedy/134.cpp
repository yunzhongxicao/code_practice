/*
@File  :134.cpp
@Author:dfc
@Date  :2022/10/29  11:12
@Desc  :����վ
*/

#include "iostream"
#include "vector"

using namespace std;
/* ���Ǳ����ⷨ �����Ѿ���ʱ��
int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
    int gas_remain;
    int cur_position;
    int next_position;
    for (int i = 0; i < gas.size(); ++i) {
        gas_remain = gas[i] - cost[i]; // ����Ǵӱ�վ��ȥ��ʣ������ Ҳ���ǵ���һվ������֮ǰ��ʣ������
        if (gas_remain<0) continue;

        int index = (i+1) % (int)gas.size(); // ���α�����д��

        while (gas_remain>=0 and index !=i)
        {
            gas_remain = gas_remain + gas[index] - cost[index]; // index��gas_remain���໥��ϵ� index�Ǳ�ʾ��һվҪ���ĵط� remain�ǵ���һվ������֮ǰ��ʣ������
            index = (index+1) % (int)gas.size();
        }
        if (gas_remain>=0 and index==i ) return i; // ֻ�д����˵ڶ����ж������� ��˵���������

    }
    return -1;
}*/

int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
    int remain_all=0,remain_run=0,start=0;
    for (int i = 0; i < gas.size(); ++i) {
        remain_all += gas[i] - cost[i];
        remain_run += gas[i] - cost[i]; // �����������ܲ��ܴ�i�ߵ�i+1
        if (remain_run<0)
        {
            start= i+1; // ���ÿ���Խ�� ��Ϊ���i=size-2 start=size-1; ���i=size-1 ��Ȼ����������жϵĻ�˵��ǰ��0->size-1���Ǹ��ͺ� size-1->0 Ҳ�Ǹ����ͺ� ���ͺľ��ж���
            remain_run = 0;
        }
    }
    return remain_all>=0?start:-1;
}


