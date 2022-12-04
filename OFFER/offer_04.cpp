/*
@File  :offer_04.cpp
@Author:dfc
@Date  :2022/12/4  17:09
@Desc  : 二维数组中的查找
*/
#include "iostream"
#include "vector"
using namespace std;

/*bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) // 这种思路是错误的 开始的想法是从左上角往右小角 确定在哪个小方块内
{
    int n = matrix.size();
    if (n==0) return false;
    int m = matrix[0].size();
    if (m==0)   return false;
    int start[2]={0,0};
    int end[2] = {n-1,m-1};
    if (target<matrix[start[0]][start[1]] or target > matrix[end[0]][end[1]])
        return false;
    while (start[0]<= end[0] and start[1]<=end[1])
    {
        if (target>=matrix[start[0]][start[1]] and target<=matrix[end[0]][end[1]])
        {
            start[0]++;
            start[1]++;
            end[0]--;
            end[1]--;
            continue;
        }
        else
        {
            break;
        }
    }
    start[0]--; start[1]--;
    end[0]++; end[1] ++;
    for (int i = start[0]; i <= end[0] ; ++i) {
        if (matrix[i][start[1]]==target or matrix[i][end[1]]== target)
            return true;
    }
    for (int j = start[1] ; j <=end[1] ; ++j) {
        if (matrix[start[0]][j] == target or matrix[end[0]][j]== target)
            return true;
    }
    return false;
}*/

/*bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) // 二叉搜索树的方法
{
    int n = matrix.size();
    if (n==0) return false;
    int m = matrix[0].size();
    if (m==0)   return false;
    int row = 0, col = m-1;
    int tmp=0;
    while (row<n and col>=0)
    {
        tmp = matrix[row][col];
        if (target<tmp)
        {
            col--;
        }
        else if (target>tmp)
            row++;
        else return true;
    }
    return false;
}*/

bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) // 二分查找的方法
{
    int n = matrix.size();
    if (n==0) return false;
    int m = matrix[0].size();
    if (m==0)   return false;

    for (int i = 0; i < n; ++i) {
        int left=0,right = m-1;
        while (left<=right)
        {
            int mid = left + (right-left)/2;
            if (matrix[i][mid]>target) right =mid-1;
            else if (matrix[i][mid]<target) left = mid+1;
            else return true;
        }
    }
    return false;
}


int main()
{
    vector<vector<int>> matrix= {{-1}};
    cout<<findNumberIn2DArray(matrix,-1);
}



