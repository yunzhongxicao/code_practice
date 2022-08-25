/*
@File  :54.cpp
@Author:dfc
@Date  :2022/8/25  11:12
@Desc  :螺旋矩阵
*/
#include "iostream"
#include "vector"
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix);

int main()
{
    vector<vector<int>> a = {{1,2,3}};
    spiralOrder(a);
}

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int loop = m/2>n/2? n/2:m/2;
    vector<int> result(m*n,0);
    int start_x = 0,start_y=0;
    int offset=1;
    int i=-1,j=-1;  // 这里不能从0开始取 因为如果只有一行的情况 下面的while循环不会经过  后面的判断+1就会超范围
    int count = 0;
    while (loop)
    {
        i = start_x;
        j= start_y;
        for (j=start_y;  j<=n-1-offset ; ++j) {
            result[count] = matrix[i][j];
            count++;
        }
        for(i = start_x;i<=m-1-offset;++i)
        {
            result[count] = matrix[i][j];
            count++;
        }
        for(j = n-offset;j>start_y;--j)
        {
            result[count] = matrix[i][j];
            count++;
        }
        for(i = m-offset;i>start_x;--i)
        {
            result[count] = matrix[i][j];
            count++;
        }
        start_x++;
        start_y++;
        loop--;
        offset++;
    }
    if (m>n)
    {
        if(n%2)
        {
            j++;
            for(i = start_x;i<=m-offset;++i)
            {
                result[count] = matrix[i][j];
                count++;
            }
        }
    }
    else
    {
        if(m%2)
        {
            i++;
            for(j = start_y;j<=n-offset;++j)
            {
                result[count] = matrix[i][j];
                count++;
            }
        }
    }
    for (int k = 0; k < result.size(); ++k) {
        cout<<result[k]<<"   ";
    }
    return result;
}