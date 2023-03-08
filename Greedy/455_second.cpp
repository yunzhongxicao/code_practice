/*
@File  :455_second.cpp
@Author:dfc
@Date  :2023/3/7  11:37
@Desc  :
*/
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s)
{
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());

    int cookie = s.size()-1, child = g.size()-1;
    int result=0;
    while (child>=0 and cookie>=0)  // ���ô����ι���� ������Ӳ����� ����Сһ��ĺ���
    {
        if (s[cookie]>= g[child])
        {
            cookie--;
            child--;
            result++;
        }
        else
        {
            child--;
        }
    }
    return result;
}

