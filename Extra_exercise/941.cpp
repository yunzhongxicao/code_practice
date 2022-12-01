/*
@File  :941.cpp
@Author:dfc
@Date  :2022/12/1  10:58
@Desc  : 有效的山脉数组
*/
#include "iostream"
#include "vector"
using namespace std;

/*
bool validMountainArray(vector<int>& arr) // 这是直接的线性扫描的方法
{
    if (arr.size()<3) return false;
    int max_index =0;
    for (int i = 1; i < arr.size(); ++i) { // 找第一个极大值
        if (arr[i] > arr[max_index]) max_index = i;
        else if (arr[i] == arr[max_index])   return false;
        else
        {
            break;
        }
    }
    if (max_index==0 or max_index == arr.size()-1) return false; // 极值不能在边界
    for (int i = max_index+1; i < arr.size() ; ++i) {
        if (arr[i]>=arr[i-1]) return false;
    }
    return true;
}*/

bool validMountainArray(vector<int>& arr)  //试下双指针的解法
{
    if (arr.size() < 3) return false;

    int left = 0;
    int right = arr.size()-1;
    while (left+1<= arr.size()-1 and  arr[left+1]>arr[left])  // 找左边第一个峰值
    {
        left++;
    }
    while (right-1 >=0 and  arr[right-1]>arr[right]) // 找右边第一个峰值
    {
        right--;
    }
    if (left == right and left!=0 and right!=arr.size()-1) return true;  // 避开单调的情况
    return false;
}