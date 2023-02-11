/*
@File  :59_second.cpp
@Author:dfc
@Date  :2023/2/11  11:17
@Desc  :ÂİĞı¾ØÕó2
*/
#include "vector"
#include "iostream"
using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    int start_x=0 ,start_y=0;
    vector<vector<int>>result(n,vector<int>(n,0));
    int circle =0;
    int count =0;
    while (circle<n/2)
    {
        for(;start_y<=n-2-circle;++start_y)
        {
            count++;
            result[start_x][start_y]=count;
        }
        for(;start_x<=n-2-circle;++start_x)
        {
            count++;
            result[start_x][start_y] = count;
        }
        for(;start_y>=1+circle;--start_y)
        {
            count++;
            result[start_x][start_y] = count;
        }
        for(;start_x>=1+circle;--start_x)
        {
            count++;
            result[start_x][start_y] = count;
        }
        circle++;
        start_y++;
        start_x++;
    }
    if (n % 2!=0)
        result[n/2][n/2] = n*n;
    return result;
}

int main()
{
    vector<vector<int>> result = generateMatrix(4);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}

