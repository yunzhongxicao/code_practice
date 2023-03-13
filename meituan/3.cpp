/*
@File  :3.cpp
@Author:dfc
@Date  :2023/3/11  20:34
@Desc  :
*/
#include "vector"
#include "iostream"
#include "unordered_map"
using namespace std;

int  main()
{
    int n;
    cin>>n;
    vector<int>star_start;
    vector<int>star_end;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin>>temp;
        star_start.push_back(temp);
    }
    for (int i = 0; i < n; ++i) {
        int temp;
        cin>>temp;
        star_end.push_back(temp);
    }
    int length=0 ,x=0;
    for (int i = 0; i < n; ++i) {
        if (star_end[i]>length) length = star_end[i];
    }
    unordered_map<int,int>my_map;
    for (int i = 0; i < n; ++i) {
        my_map[star_start[i]]++;
        my_map[star_end[i]]--;
    }
    int cur=0; int max_value =-1; int time =0;
    for (int i = 0; i <=length  ; ++i) {
        if (my_map[i]>=0)
        {
            cur += my_map[i];
            if (cur>max_value)
            {
                max_value = cur;
                time =1;
            }
            else if (cur==max_value)
            {
                time++;
            }
        }
        else
        {
            if (cur>max_value)
            {
                max_value =cur;
                time =1;
            }
            else if (cur==max_value)
            {
                time++;
            }
            cur += my_map[i];
        }
    }
    cout<<max_value<<time;
}

