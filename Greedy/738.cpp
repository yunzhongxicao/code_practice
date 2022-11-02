/*
@File  :738.cpp
@Author:dfc
@Date  :2022/11/1  21:35
@Desc  : ��������������
*/
#include "iostream"
#include "vector"
#include "algorithm"
#include "cmath"
using namespace std;

int monotoneIncreasingDigits(int n);

int monotoneIncreasingDigits(int n)
{
    vector<int> a;
    int n_copy = n;
    while (n_copy>0)
    {
        int tmp = n_copy % 10;
        a.push_back(tmp);
        n_copy = n_copy / 10;
    }
    // ע�� ��ʱ�������Ƿ��ŵ� �Ӹ�λ�����λ
/*     ���ֱ���˳���Ǵ���� ����Ҫ�ӵ�λ����λ����
    int flag = -1;
    for (int i = a.size()-1 ; i>=1 ; --i) {  // ���ԴӸ�λ���λ��������ΪҪ��� ���Ը�λ������������ ��������˵ݼ������ ��ô��ֻ�ܰѵ�ǰ-1 �����ȫ�����9 �����϶�������
        if (a[i]>a[i-1])
        {
            a[i]--;
            flag = i-1;
            break;
        }
    }
    for (int i =flag ; i >=0 ; --i) {
        a[i] = 9;
    }*/

    // �ҵ��ӵ�λ����λ���������һλ������֮��ĵ�λ����Ϊ9
    int flag = -1;
    for (int i = 1; i < a.size(); ++i) {
        if (a[i]>a[i-1])
        {
            a[i]--;
            flag=i-1;
        }
    }
    for (int i = 0; i <=flag ; ++i) {
        a[i]=9  ;
    }
    int result=0;
    for (int i = 0; i < a.size(); ++i) {
        result+=a[i]* pow(10,i);
    }
    return result;
}

int main()
{
    int n = 332;
    int result = monotoneIncreasingDigits(n);
    cout<<result;
}

