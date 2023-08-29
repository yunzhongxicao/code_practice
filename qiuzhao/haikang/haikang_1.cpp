/*
@File  :haikang_1.cpp
@Author:dfc
@Date  :2023/8/22  23:21
@Desc  :
*/
#include "iostream"
#include "vector"
#include "algorithm"
#include "string"

using namespace std;

vector<int> path;
vector<vector<int>> result;

void backtracking(vector<int>&nums, vector<int>&visited)
{
    if (path.size()==nums.size())
    {
        result.push_back(path);
        return;
    }
    for (int i = 0; i <=nums.size()-1   ; ++i) {
        if (visited[i]==1) continue;
        path.push_back(nums[i]);
        visited[i] = 1;
        backtracking(nums,visited);
        path.pop_back();
        visited[i] = 0;
    }
}

int main()
{
    vector<int> nums;
    string tmp = "";
    char a;
    while (cin.get(a))
    {
        if (a==',')
        {
            nums.push_back(stoi(tmp));
            tmp = "";
        }
        else if (a=='\n')
        {
            nums.push_back(stoi(tmp));
            break;
        }
        else
        {
            tmp += a;
        }
    }
    // for (int i = 0; i < nums.size(); ++i) {
    //     cout<<nums[i]<<endl;
    // }
    // sort(nums.begin(),nums.end());
    vector<int> visited(nums.size(),0);
    backtracking(nums,visited);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}

