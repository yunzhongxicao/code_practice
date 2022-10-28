/*
@File  :55.cpp
@Author:dfc
@Date  :2022/10/28  11:41
@Desc  : ��Ծ��Ϸ
*/

#include "iostream"
#include "vector"

using namespace std;

bool canJump(vector<int>& nums);
bool canJump(vector<int>& nums)
{
    int max_index = 0;
    for (int i = 0; i < nums.size()-1; ++i) {
        if (i<=max_index)  // ֻҪ�����ķ�Χ�ڣ����������� Ȼ��Ϳ���ǰ�ܵ������Χ
        {
            int tpm = i+nums[i];
            max_index = max(max_index,tpm);
        }
    }
    return max_index >= nums.size() - 1;
}

int main()
{
    vector<int> a = {2,3,1,1,4};
    bool b = canJump(a);
    cout<<b;
}
