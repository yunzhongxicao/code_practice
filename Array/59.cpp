/*
@File  :59.cpp
@Author:dfc
@Date  :2022/8/25  10:36
@Desc  : ��������
*/
#include "iostream"
#include "vector"
using namespace std;

vector<vector<int>> generateMatrix(int n);

int main()
{
    generateMatrix(5);
}

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> res(n, vector<int>(n, 0)); // ʹ��vector����һ����ά����
    int start_x=0,start_y = 0;
    int loop = n/2;
    int i, j;
    int offset = 1;
    int  count = 1;
    int mid = n/2;
    while (loop>0)
    {
        i = start_x;
        j = start_y;
        for (j = start_y; j <= n-1-offset; ++j) {   // ����i j�Ĳ��ܼ�int ���ж��� ��Ȼ���ɾֲ����� �����󲻻�����
            res[i][j]= count;
            count++;
        }
        for (i = start_x; i <= n-1-offset; ++i) {
            res[i][j]= count;
            count++;
        }
        for (j = n-offset; j >start_y ; --j) {
            res[i][j]= count;
            count++;
        }
        for (i = n-offset; i >start_x ; --i) {
            res[i][j]= count;
            count++;
        }
        start_x++;
        start_y++;
        loop--;
        offset++;
    }
    if (n%2)
    {
        res[mid][mid] = count;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <n; ++j) {
            cout<<res[i][j]<<"   ";
        }
        cout<<endl;
    }
    return res;

}

