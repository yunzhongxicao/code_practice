/*
@File  :offer_29.cpp
@Author:dfc
@Date  :2022/12/23  15:14
@Desc  : À≥ ±’Î¥Ú”°æÿ’Û
*/
#include "iostream"
#include "vector"
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    vector<int> result;

    int m = matrix.size();
    if (m==0) return result;
    int n = matrix[0].size();
    if (n==0)return result;
    int start_x= 0,start_y = 0;
    int  count=0;
    while (count< min(m,n)/2 )
    {
        for (;start_x<=n-1-count-1;++start_x) {
            result.push_back(matrix[start_y][start_x]);
        }
        for(;start_y<=m-1-count-1;++start_y)
        {
            result.push_back(matrix[start_y][start_x]);
        }
        for(;start_x>=count+1;--start_x)
        {
            result.push_back(matrix[start_y][start_x]);
        }
        for(;start_y>=count+1;--start_y)
        {
            result.push_back(matrix[start_y][start_x]);
        }
        count++;
        start_x++;
        start_y++;
    }
    if (min(m,n)%2==0) return result;
    if (n>=m)
    {
        for(;start_x<=n-1-count;++start_x)
        {
            result.push_back(matrix[start_y][start_x]);
        }
    }
    else
    {
        for(;start_y<=m-1-count;++start_y)
            result.push_back(matrix[start_y][start_x]);
    }
    return result;
}

