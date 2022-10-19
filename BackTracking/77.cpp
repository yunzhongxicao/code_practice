/*
@File  :77.cpp
@Author:dfc
@Date  :2022/10/18  21:13
@Desc  : 组合问题
*/

#include "vector"
#include "iostream"


using namespace std;


vector<int> path;
vector<vector<int>> result;
void backtracking(int n, int k, int start_index);
vector<vector<int>> combine(int n, int k);

vector<vector<int>> combine(int n, int k)
{
    int start_index = 1;
    backtracking(n,k,start_index);
    return result;
}

void backtracking(int n, int k, int start_index)
{
    if (path.size()==k)
    {
        result.push_back(path);
        return;
    }
    for (int i = start_index; i <=n-(k-path.size())+1 ; ++i) {
        path.push_back(i);
        backtracking(n,k,i+1);
        path.pop_back();
    }
}

int main()
{
    combine(4,2);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}