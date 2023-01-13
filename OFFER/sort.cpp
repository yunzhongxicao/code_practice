/*
@File  :sort.cpp
@Author:dfc
@Date  :2023/1/12  23:03
@Desc  : ���������㷨��ʵ��
*/
#include "iostream"
#include "vector"
using namespace std;

void bubble_sort(vector<int> &a) // ð������
{
    int n = a.size();
    for (int i = n-2; i >=0 ; --i) {  // ÿ�ν����Ľ����� ��һ���ǵ�n-2���� ���һ���ǵ�0����
        int flag =0;
        for (int j = 0; j <=i ; ++j) {
            if (a[j]>=a[j+1]) {
                swap(a[j], a[j + 1]);
                flag = 1;
            }
        }
        if (flag==0) // �����;û���� ˵�����������ǰ����
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
        if (high>low) // ֻ�д�����һ��������˵��������ҵ���һ����� Ҫ�ź��ȥ
        {
            a[high] = a[low];
            high--;
        }
    }
    a[low] = k ; // ��ʱ�����ص�
    return low;
}
void quick_sort(vector<int>&a, int low, int high)
{
    if (low>=high)  // ���п��ܳ��ִ��ڵ������
        return;
    int middle = divide(a,low,high);
    quick_sort(a,low,middle-1);
    quick_sort(a,middle+1,high);
}

void merge(vector<int>&a, int left,int middle, int right)
{
    // �����left-> middle �ұ���middle+1��> right
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
    for (int l = left, m=0; l <=right; ++l,++m) { // ע�� ����ֻ�Ǻϲ��� ���� ��������a����
        a[l] = temp[m];
    }
}

void merge_sort(vector<int>&a,int left, int  right)
{
    int  middle = (left+right)/2;
    if (left==right) return; // ֻ��һ����ʱ����Ҫ����
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

