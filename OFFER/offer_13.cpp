/*
@File  :offer_13.cpp
@Author:dfc
@Date  :2023/1/25  13:39
@Desc  : �����˵��˶���Χ
*/
#include "iostream"
#include "vector"

using namespace std;

/*int movingCount(int m, int n, int k) // ������
{
    vector<vector<int>>dp(m,vector<int>(n,k+1));
    // dp[i][j]��ʾ�յ�����Ϊi j�ĸ�����
    for (int i = 0; i <=min(k,m-1) ; ++i) {
        dp[i][0] = i+1;
    }
    for (int j = 0; j <=min(k,n-1) ; ++j) {
        dp[0][j] = j+1;
    }
    for (int i = 1; i <m ; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];
            if (i/10 + i%10 + j/10 + j%10<=k)
                dp[i][j] +=1;
        }
    }
    return dp[m-1][n-1];
}*/
void dfs(int i, int j,vector<vector<int>> &visit,int m, int  n,int k);
int result=0;
int movingCount(int m, int n, int k)
{
    vector<vector<int>> visit(m,vector<int>(n,0));
    dfs(0,0,visit,m,n,k);
    return result;
}

void dfs(int i, int j,vector<vector<int>> &visit,int m, int  n,int k)
{
    if (i>=m or j>=n or visit[i][j]==1) return; // ���߽� �����Ѿ����ʹ���
    visit[i][j] = 1;
    if (i%10 + i/10 + j%10+ j/10>k) return; // ���Լ����±� �ұ߶��������� ���ü�������������
    result++;
    dfs(i+1,j,visit,m,n,k);
    dfs(i,j+1,visit,m,n,k);
}

int main()
{
    cout<<movingCount(4,4,2);
}

