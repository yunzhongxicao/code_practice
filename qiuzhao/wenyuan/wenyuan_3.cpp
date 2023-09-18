/*
@File  :wenyuan_3.cpp
@Author:dfc
@Date  :2023/9/10  19:43
@Desc  :
*/
#include "iostream"
#include "vector"

using namespace std;
vector<int> left = {0,-1};
vector<int> right = {0,1};
vector<int> up = {-1,0};
vector<int> down = {1,0};
vector<int> right_up = {-1,1};
vector<int> right_down = {1,-1};

// 右 下 右上 右下
vector<vector<int>> directions = {{0,1},{1,0},{-1,1}, {1,-1}} ;

int main()
{
//    directions.push_back(right);
    int N, M;
    cin>>N>>M;
    vector<vector<int>> grid(N+1, vector<int>(M+1,0));
    int num_a =1, num_b = 2;
    int x1_a = 1, x2_a = 1, x1_b = N, x2_b = M;
    int d = 0;
    int m_x1 = N/2+1;
    int m_x2 = M/2 +1;
    while (true)
    {
        if (x1_a == 1 and d == 0)  // 第一排 且向上来的
        {
            x1_a += directions[d][0];
            x2_a += directions[d][1];
            x1_b = 2 * m_x1 - x1_a;
            x2_b = 2 * m_x2 - x2_a;
            if (x1_a == x1_b and x2_a == x2_b) break;
            num_a  +=2;
            grid[x1_a][x2_a] = num_a;
            d = 3;
            while (x2_a !=1)
            {
                x1_a += directions[d][0];
                x2_a += directions[d][1];
                num_a  +=2;
                grid[x1_a][x2_a] = num_a;
            }
        }
        else if (x2_a == 1 and d==3 and x1_a<N)
        {
            d = 2;
            x1_a += directions[d][0];
            x2_a += directions[d][1];
            num_a  +=2;
            grid[x1_a][x2_a] = num_a;
            d= 2;
            while (x1_a !=1)
            {
                x1_a += directions[d][0];
                x2_a += directions[d][1];
                num_a  +=2;
                grid[x1_a][x2_a] = num_a;
            }
        }
        else if (x2_a == 1 and d==3 and x1_a==N)
        {
            d = 0;
            x1_a += directions[d][0];
            x2_a += directions[d][1];
            num_a  +=2;
            grid[x1_a][x2_a] = num_a;
            d= 2;
            while (x1_a !=1)
            {
                x1_a += directions[d][0];
                x2_a += directions[d][1];
                num_a  +=2;
                grid[x1_a][x2_a] = num_a;
            }
        }
    }
}