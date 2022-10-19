/*
@File  :216.cpp
@Author:dfc
@Date  :2022/10/19  11:00
@Desc  : ����ܺ�3
*/

#include "iostream"
#include "vector"

using namespace std;

vector<int> path;
vector<vector<int>> result;
int sum=0;
vector<vector<int>> combinationSum3(int k, int n);
void backtracking(int k ,int n ,int start_index);

void backtracking(int k ,int n ,int start_index)
{
    if (path.size()==k and sum==n)
    {
        result.push_back(path);
        return;
    }
    if (path.size()==k and sum !=n)
    {
        return;
    }
    if (sum>n)
        return;
    for (int i = start_index; i <=9-(k-path.size())+1 ; ++i) {
        sum+=i;
        path.push_back(i);
        if (sum>n)
        {
            sum-=i;  // �����֦һ��Ҫ�ѻ��ݸ����ˣ��ص���һ��
            path.pop_back();
            break;  // break�Ļ�����ͽ����� �ص���һ��
        }
        backtracking(k,n,i+1);
        path.pop_back();
        sum-=i;
    }
}

vector<vector<int>> combinationSum3(int k, int n)
{
    backtracking(k,n,1);
    return result;
}

int main()
{
    combinationSum3(3,9);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}

