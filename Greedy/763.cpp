/*
@File  :763.cpp
@Author:dfc
@Date  :2022/10/31  15:17
@Desc  : ������ĸ����
*/
#include "iostream"
#include "string"
#include "vector"

using namespace std;
/*
vector<int> partitionLabels(string s)
{
    vector<int> index(26,-1)  ;
    for (int i = 0; i < s.size(); ++i) { // �ҵ�ÿ���ַ�����Զλ��
        int tmp = s[i]-'a';
        index[tmp] = i;
    }
    int max_index=index[s[0]-'a']; // ÿһ�ε���Զ����
    vector<int> result;
    int num =0;
    for (int i = 0; i < s.size(); ++i) {
        int tmp = s[i] - 'a';
        if (i > max_index) // ÿ��ֻ���ҵ���ǰ���Χ����һ���� ˵����һ�ν�����  Ȼ��ѹ���� Ȼ�����¼�����һ�����Χ
        {
            result.push_back(num);
            num= 1;
            max_index = index[tmp];
        }
        else
        {
            num++;
            max_index = max(max_index,index[tmp]);
        }
    }
    result.push_back(num); // ���һ�������޷��ҵ���Զ�������һ���� ����Ҫ�ֶ�ѹ����
    return result;
}*/



vector<int> partitionLabels(string s)
{
    vector<int> index(26,-1)  ;
    for (int i = 0; i < s.size(); ++i) { // �ҵ�ÿ���ַ�����Զλ��
        int tmp = s[i]-'a';
        index[tmp] = i;
    }
    int max_index=-1; // ÿһ�ε���Զ����
    vector<int> result;
    int num =0;
    for (int i = 0; i < s.size(); ++i) {
        int tmp = s[i] - 'a';
        max_index = max(max_index,index[tmp]); // ÿ������һ�µ�ǰƬ�ε���Զ���� Ȼ�����ж��Ƿ�Ƭ�ν���
        if (i == max_index) // �ҵ���ȵ� �϶��ǽ����� ��ʱ��������max_index ��Ϊ��һ����ǰ��϶������ã���һ�ε�indexһ�������ڴ�
        {
            num++;
            result.push_back(num);
            num= 0;
        }
        else
        {
            num++;
        }
    }
    return result;
}

int main()
{
    string s =  "ababcbacadefegdehijhklij";
//    string s = "caedbdedda";
    vector<int> result = partitionLabels(s);

    for (int i = 0; i < result.size(); ++i) {
        cout<< result[i] << " ";
    }
}

