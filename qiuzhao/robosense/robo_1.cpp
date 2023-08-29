/*
@File  :robo_1.cpp
@Author:dfc
@Date  :2023/8/26  15:44
@Desc  :
*/
#include "iostream"
#include "vector"
using namespace std;

bool canJump(vector<int>& nums)
{
    int max_index = 0;
    for (int i = 0; i < nums.size()-1; ++i) {
        if (i<=max_index)
        {
            int tpm = i+nums[i];
            max_index = max(max_index,tpm);
        }
    }
    return max_index >= nums.size() - 1;
}


int  main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    for (int i = 0; i < n; ++i) {
        cin>>nums[i];
    }
    if (canJump(nums)) cout<<"true"<<endl;
    else cout<<"false"<<endl;
}

