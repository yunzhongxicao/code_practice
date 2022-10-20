/*
@File  :40.cpp
@Author:dfc
@Date  :2022/10/20  9:36
@Desc  :
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

    if (sum>target) return; // 后面的for是进入下一层的计算 在这之前如果已经超了 就不往后加了
    if (sum==target)
    {
        result.push_back(path);
        return;
    }
    for (int i = start_index; i < candidates.size(); ++i) {
        if (i>start_index and candidates[i]==candidates[i-1]) continue;
        sum += candidates[i];
        path.push_back(candidates[i]);
        if (sum>target)  // 这里写法有个前提 默认后面的比前面大 所以要先排序
        {
            sum-=candidates[i];
            path.pop_back();
            return;
        }
        backtracking(candidates,target,i+1);
        path.pop_back();
        sum -=candidates[i];
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target);
vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
    sort(candidates.begin(),candidates.end());
    backtracking(candidates,target,0);
    return result;
}

int main()
{
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    combinationSum2(candidates,target);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}