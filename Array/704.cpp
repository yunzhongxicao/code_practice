/*
@File  :704.cpp
@Author:dfc
@Date  :2022/7/31  15:37
@Desc  : 704-¶þ·Ö²éÕÒ
*/
#include "iostream"
#include "vector"
using namespace std;
int search(vector<int>&nums, int target);


int main()
{
    vector<int> a = {-1,0,3,5,9,12};
    int  target = 2;
    search(a,target);
}

int search(vector<int>&nums, int target)
{
    int num_length = nums.size();
    for (int i = 0; i < num_length; ++i) {
        if (nums[i] == target)
        {
            cout<<i;
            return i;
        } else if (i==num_length-1)
        {
            cout<<-1;
            return -1;
        }
    }

}