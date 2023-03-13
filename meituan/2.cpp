/*
@File  :2.cpp
@Author:dfc
@Date  :2023/3/11  20:07
@Desc  :
*/
#include "bits/stdc++.h"

using namespace std;
vector<pair<int,int>> direction = {{1,0},{0,1}};

int get_res(vector<vector<int>> &map, vector<vector<int>>&money,int n, int m, int k)
{
    queue<vector<int>> qu;
    qu.push({0,0,0});
    int res= 0;
    while (!qu.empty())
    {
        int x = qu.front()[0], y = qu.front()[1], z= qu.front()[2];
        qu.pop();
        for (auto i:direction) {
            int now_x = x+i.first, now_y = y+i.second;
            if (now_x>=n or now_y>=m) continue;
            if (map[x][y] != map[now_x][now_y])
            {
                if (z+map[now_x][now_y]<k) continue;
                qu.push({now_x,now_y,z-k+money[now_x][now_y]});
            }
            qu.push({now_x,now_y,z+money[now_x][now_y]});
            res = max(res,z+money[now_x][now_y]);
        }
    }
    return res;
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<string>map_s;
    for (int i = 0; i < n; ++i) {
        string temp;
        cin>>temp;
        map_s.push_back(temp);
    }
    vector<vector<int>> money(n,vector<int>(m,0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>money[i][j];
        }
    }
    vector<vector<int>>map(map_s.size(),vector<int>(m,0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (map_s[i][j]=='R')
                map[i][j] = 2;
            if (map_s[i][j]=='B')
                map[i][j] = 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout<<money[i][j]<<" ";
        }
        cout<<endl;
    }

    int res = get_res(map,money,n,m,k);
    cout<<res;
}

