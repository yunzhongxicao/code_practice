/*
@File  :27.cpp
@Author:dfc
@Date  :2022/8/22  10:01
@Desc  :  �Ƴ�Ԫ��
*/
#include "iostream"
#include "vector"
using namespace std;
int removeElement_1(vector<int>& nums, int val);
int removeElement_2(vector<int>& nums, int val);


int main()
{
    vector<int> a = {3,2,2,3};
    int val = 3;
    // int size =     removeElement_1(a,val);
    int size =     removeElement_2(a,val);
    // cout<<size;
    // return 0;
}

int removeElement_1(vector<int>& nums, int val)  // ���Ǳ����ⷨ
{
    int size = nums.size();
    for (int i = 0; i < size; ++i) {
        int tmp = nums[i];
        if (tmp == val)
        {
            for (int j = i; j < size-1; ++j) {
                nums[j] = nums[j+1];
            }
            size--;
            i--; // ��Ϊ�±�i�Ժ����ֵ����ǰ�ƶ���һλ������iҲ��ǰ�ƶ�һλ
        }

    }
    cout<<size;
    return size;
}

int removeElement_2(vector<int>& nums, int val)  //����˫ָ�뷨
{
    int size = nums.size();
    int  j = 0;
    for (int i = 0; i < size; ++i) {
        if (nums[i] != val)
        {
            nums[j] = nums[i];
            j++;
        }
    }
    cout<< j;
    return j;
}