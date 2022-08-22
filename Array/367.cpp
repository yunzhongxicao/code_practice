/*
@File  :367.cpp
@Author:dfc
@Date  :2022/8/1  17:01
@Desc  :����һ�� ������ num ����дһ����������� num ��һ����ȫƽ�������򷵻� true �����򷵻� false ��
*/
#include "iostream"
#include "vector"
using namespace std;

bool isPerfectSquare(int x);

int main()
{
    bool a = isPerfectSquare(5);
    cout<<a;
}
bool isPerfectSquare(int x)
{
    int left = 0;
    int right = x;
    int middle;
    if (x<=1)
        return true;
    while (left<=right)
    {
        middle = (int)(left+right)/2;
        if (middle >x/middle)
        {
            right = middle-1;
        }
        else if (middle  < x/middle)  //ע�������ó��� ��ֹ���
        {
            left = middle +1;
        }
        else
        {
            if (x%middle == 0)  //����Ҫ�ж�һ���Ƿ�������
            {
                return true;
            }
            else
            {
               left = middle+1;
            }
        }
    }
    return false;
}