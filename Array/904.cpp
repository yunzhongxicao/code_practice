/*
@File  :904.cpp
@Author:dfc
@Date  :2022/8/23  10:28
@Desc  :  ˮ������
*/

#include "iostream"
#include "vector"
using namespace std;

int totalFruit(vector<int>& fruits);

int main()
{
    vector<int> a = {1,2,3,2,2};
    totalFruit(a);
}

int totalFruit(vector<int>& fruits)
{
    int j = 0;
    int sub_length = 0;
    int fruit_1 = fruits[0];
    int fruit_2 = INT32_MIN;
    int result = 0;
    for (int i = 0; i < fruits.size() ; ++i) {
        if (fruits[i] == fruit_1 or fruits[i] == fruit_2)  // ǰ��������if��Ϊ��ȷ���ʼ����ˮ����ֵ����Ϊһ��ʼ�϶��ǿ���һֱ�ӵ�
        {
            sub_length++;
            result = result<sub_length?sub_length:result;

        } else if(fruit_2 == INT32_MIN)
        {
            fruit_2 = fruits[i];
            // j = i;
            sub_length++;
            result = result<sub_length?sub_length:result;

        }
        if (fruit_2 != INT32_MIN)   //������һ��Ҫ�ȵ��ڶ���ˮ����ֵ֮�󣬲Ž����ж��³��ֵ�
        {
            if (fruits[i] != fruit_1 and fruits[i] != fruit_2)
            {
                fruit_2 = fruits[i];
                fruit_1 = fruits[i-1];  // �������ڴ��³��ֵ����󻬶�����Ϊֻ��Ҫ֪������ˮ����ɶ���У�����Ҫ֪��λ��
                j = i-1;
                sub_length= 1;
                while (fruits[j] == fruit_1)
                {
                    j--;
                    sub_length++;
                }
                result = result<sub_length?sub_length:result;

            }
        }

    }
    cout<<result;
    return result;
}
