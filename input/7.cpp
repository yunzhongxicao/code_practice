/*
@File  :7.cpp
@Author:dfc
@Date  :2023/3/5  13:48
@Desc  :
*/
#include "iostream"
using namespace std;

int main()
{
    int sum =0;
    int a;
    while (cin>>a)
    {
        sum += a;
        if (cin.get()=='\n') // ÿ�ζ��������getȥ���������Ľ����ַ�������cin���
        {
            cout<<sum<<endl;
            sum=0;
        }
    }
}