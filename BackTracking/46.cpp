/*
@File  :46.cpp
@Author:dfc
@Date  :2022/10/21  23:59
@Desc  : ȫ����
*/

#include "iostream"
#include "vector"


using namespace std;

vector<int> path;
vector<vector<int>> result;

void backtracking(vector<int> nums,vector<int> used) // ��ʵ����used�Ӳ������ö����� ��Ϊͨ�����ݺ���ʵֵ��һ����
{
    if (path.size()==nums.size())
    {
        result.push_back(path);
        return;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (used[i] ==0)
        {
            path.push_back(nums[i]);
            used[i]=1;
            backtracking(nums,used);
            used[i]=0;
            path.pop_back();
        }
        else continue;
    }
}

vector<vector<int>> permute(vector<int>& nums)
{
    vector<int> used(nums.size(),0);
    backtracking(nums,used);
    return result;
}

int main()
{
    vector<int> nums = {1,2,3};
    permute(nums);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}
