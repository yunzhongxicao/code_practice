/*
@File  :sort.cpp
@Author:dfc
@Date  :2023/1/12  23:03
@Desc  : 各种排序算法的实现
*/
#include "iostream"
#include "vector"
using namespace std;

void bubble_sort(vector<int> &a) // 冒泡排序
{
    int n = a.size();
    for (int i = n-2; i >=0 ; --i) {  // 每次交换的结束点 第一次是到n-2结束 最后一次是到0结束
        int flag =0;
        for (int j = 0; j <=i ; ++j) {
            if (a[j]>=a[j+1]) {
                swap(a[j], a[j + 1]);
                flag = 1;
            }
        }
        if (flag==0) // 如果中途没交换 说明排序可以提前结束
            break;
    }
}

int divide(vector<int> &a, int low , int high)
{
    int k = a[low];
    while (low<high)
    {
        while (a[high]>=k and high>low) high--;
        if (high>low)
        {
            a[low] = a[high];
            low++;
        }
        while (a[low]<=k and high>low) low++;
        if (high>low) // 只有触发第一个条件才说明在左边找到了一个大的 要放后边去
        {
            a[high] = a[low];
            high--;
        }
    }
    a[low] = k ; // 此时两个重叠
    return low;
}
void quick_sort(vector<int>&a, int low, int high)
{
    if (low>=high)  // 是有可能出现大于的情况的
        return;
    int middle = divide(a,low,high);
    quick_sort(a,low,middle-1);
    quick_sort(a,middle+1,high);
}

void merge(vector<int>&a, int left,int middle, int right)
{
    // 左边是left-> middle 右边是middle+1—> right
    int i=left,j=middle+1,k=0;
    vector<int>temp(right-left+1);
    while (i<=middle and j<=right)
    {
        if (a[i]<=a[j])
        {
            temp[k] = a[i];
            i++;
            k++;
        }
        else
        {
            temp[k]= a[j];
            j++;
            k++;
        }
    }
    while (i<=middle)
    {
        temp[k] = a[i];
        k++; i++;
    }
    while (j<=right)
    {
        temp[k] = a[j];
        k++; j++;
    }
    for (int l = left, m=0; l <=right; ++l,++m) { // 注意 这里只是合并了 部分 不是整个a数组
        a[l] = temp[m];
    }
}

void merge_sort(vector<int>&a,int left, int  right)
{
    int  middle = (left+right)/2;
    if (left==right) return; // 只有一个的时候不需要排序
    merge_sort(a,left,middle);
    merge_sort(a,middle+1,right);
    merge(a,left,middle,right);
}

int main()
{
    vector<int> a = {5,7,3,0,4,2,1,9,6,8};
    // vector<int> a = {1,3,4,2,5,6};

    // bubble_sort(a);
    // divide(a,0,a.size()-1 );
    // quick_sort(a,0,a.size()-1);
    merge_sort(a,0,a.size()-1);
    // merge(a,0,2,a.size()-1);
    for (int i = 0; i < a.size(); ++i) {
        cout<<a[i]<<" ";
    }
}

