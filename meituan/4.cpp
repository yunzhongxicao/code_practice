/*
@File  :4.cpp
@Author:dfc
@Date  :2023/3/11  19:21
@Desc  :
*/
#include "bits/stdc++.h"
using namespace std;

int main()
{
    string order_d, order_w;
    cin>>order_d;
    cin>>order_w;
    vector<vector<int>> place(16,vector<int>(16,0)  );
    // 初始化都是0 表示没被占领 1表示小d占领 2表示小w占领
    vector<int>d_xy(2,0);
    vector<int>w_xy(2,0);
    d_xy[0]=0; d_xy[1]=0;
    w_xy[0]=15; w_xy[1] =15;

    //
    int d_direction = 1;  // 0是上 1是右 2是下 3是左
    int w_direction = 3;

    //
    int d_num=1, w_num = 1;
    int num =0;
    char winner = 'P';

    int d_zhuangtai =1; // 1表示没被摧毁
    int w_zhuangtai =1;

    for (int i = 0; i < order_d.size(); ++i) {
        num = i;
        char order_d_temp = order_d[i];
        char order_w_temp = order_w[i];
        if (order_d_temp=='F')
        {
            if (d_direction==1 and w_xy[1]>d_xy[1])
                w_zhuangtai=0;
            if (d_direction==0 and w_xy[0]<d_xy[0])
                w_zhuangtai=0;
            if (d_direction==2 and w_xy[0]>d_xy[0])
                w_zhuangtai=0;
            if (d_direction==3 and w_xy[1]<d_xy[1])
                w_zhuangtai=0;
        }
        if (order_w_temp=='F')
        {
            if (w_direction==1 and d_xy[1]>w_xy[1])
                d_zhuangtai=0;
            if (w_direction==0 and d_xy[0]<w_xy[0])
                d_zhuangtai=0;
            if (w_direction==2 and d_xy[0]>w_xy[0])
                d_zhuangtai=0;
            if (w_direction==3 and d_xy[1]<w_xy[1])
                d_zhuangtai=0;
        }
        if (d_zhuangtai==1 and w_zhuangtai==0)
        {
            winner='D';
            break;
        }
        else if (d_zhuangtai==0 and w_zhuangtai==1)
        {
            winner='W';
            break;
        }
        else if (d_zhuangtai==0 and w_zhuangtai==0)
        {
            winner='P';
            break;
        }
        int flag =0;
        if (order_d_temp=='U' and d_xy[0]>=1 and place[d_xy[0]][d_xy[1]-1]==0)
        {
            flag++;
            d_xy[0]--;

        }
    }
}

