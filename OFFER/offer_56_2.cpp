/*
@File  :offer_56_2.cpp
@Author:dfc
@Date  :2023/1/14  22:57
@Desc  : �����г��ֵĴ���2
*/
#include "iostream"
#include "vector"
using namespace std;

int singleNumber(vector<int>& nums)
{
    vector<int> count(32,0);
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < count.size(); ++j) {
            count[31-j] += ((nums[i]>>j) & 1);
        }
    }
    int result = 0;
    for (int i = 0; i < count.size(); ++i) {
        count[i] = count[i] %3;
    }
    for (int i = 0; i < count.size(); ++i) {
        result = result <<1;  // ע�� �������仰��˳���ܷ� �Ե�һ��Ϊ�� ��ʵ��Ӧ�ð����λͨ�������Ƶ����ұ� Ȼ��ȵ�����һ�� ���ֽ�������
        result = result | (count[i]);

    }
    return result;
}

int main()
{
    vector<int> nums = {3,3,5,3};
    cout<<singleNumber(nums);
}
