/*
@File  :taobao_1.cpp
@Author:dfc
@Date  :2023/9/2  13:52
@Desc  :
*/
#include "iostream"
#include "vector"
#include "unordered_map"
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> nums(n,0);
    for (int i = 0; i < n; ++i) {
        cin>>nums[i];
    }
    long long result = 0;
    for (int i = 0; i <= nums.size()-4; ++i) {
        for (int j = i+1; j <=nums.size()-3  ; ++j) {
            for (int k = j+1; k <=nums.size()-2 ; ++k) {
                for (int l = k+1    ; l <=nums.size()-1 ; ++l) {
                    if (nums[i]+nums[j] ==(nums[k] ^ nums[l]) )
                        result++;
                }
            }
        }
    }
    cout<<result % (1000000007);
}

