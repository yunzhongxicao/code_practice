/*
@File  :39.cpp
@Author:dfc
@Date  :2022/10/19  13:05
@Desc  : ����ܺ�
*/

#include "string"
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;


vector<int> path;
vector<vector<int>> result;
int sum=0;

void backtracking(vector<int>& candidates, int target,int start_index)
{
    if (path.size()>=150)
        return;
    if (sum>target) return; // �����for�ǽ�����һ��ļ��� ����֮ǰ����Ѿ����� �Ͳ��������
    if (sum==target)
    {
        result.push_back(path);
        return;
    }
    for (int i = start_index; i < candidates.size(); ++i) {
        sum += candidates[i];
        path.push_back(candidates[i]);
        if (sum>target)  // ����д���и�ǰ�� Ĭ�Ϻ���ı�ǰ��� ����Ҫ������
        {
            sum-=candidates[i];
            path.pop_back();
            return;
        }
        backtracking(candidates,target,i);
        path.pop_back();
        sum -=candidates[i];
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target);
vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    sort(candidates.begin(),candidates.end());
    backtracking(candidates,target,0);
    return result;
}

int main()
{
    vector<int> candidates = {8,7,4,3};
    int target = 11;
    combinationSum(candidates,target);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}

