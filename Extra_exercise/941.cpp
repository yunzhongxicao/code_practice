/*
@File  :941.cpp
@Author:dfc
@Date  :2022/12/1  10:58
@Desc  : ��Ч��ɽ������
*/
#include "iostream"
#include "vector"
using namespace std;

/*
bool validMountainArray(vector<int>& arr) // ����ֱ�ӵ�����ɨ��ķ���
{
    if (arr.size()<3) return false;
    int max_index =0;
    for (int i = 1; i < arr.size(); ++i) { // �ҵ�һ������ֵ
        if (arr[i] > arr[max_index]) max_index = i;
        else if (arr[i] == arr[max_index])   return false;
        else
        {
            break;
        }
    }
    if (max_index==0 or max_index == arr.size()-1) return false; // ��ֵ�����ڱ߽�
    for (int i = max_index+1; i < arr.size() ; ++i) {
        if (arr[i]>=arr[i-1]) return false;
    }
    return true;
}*/

bool validMountainArray(vector<int>& arr)  //����˫ָ��Ľⷨ
{
    if (arr.size() < 3) return false;

    int left = 0;
    int right = arr.size()-1;
    while (left+1<= arr.size()-1 and  arr[left+1]>arr[left])  // ����ߵ�һ����ֵ
    {
        left++;
    }
    while (right-1 >=0 and  arr[right-1]>arr[right]) // ���ұߵ�һ����ֵ
    {
        right--;
    }
    if (left == right and left!=0 and right!=arr.size()-1) return true;  // �ܿ����������
    return false;
}