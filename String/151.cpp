/*
@File  :151.cpp
@Author:dfc
@Date  :2022/9/2  15:45
@Desc  :��ת�ַ����еĵ���
*/

#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
using namespace std;

string reverseWords_1(string s);
string reverseWords_2(string s);
void removeExtraSpaces(string& s);
void reverse_substr(string &s,int start,int end);


int main()
{
    string a = "  hello world  ";
    string b = reverseWords_2(a);
    cout<<b;
}

string reverseWords_1(string s) // �����û������ǰ�Լ�д�İ汾���õ�����Ƭ�ͷ�ת����������ͬʱ�ռ临�Ӷȸ�
{
    vector<string> result_vector;

    for (int i = 0; i < s.size(); ) {
        if (s[i]==' ') {
            i++;
            continue;
        }
        int j=i+1;
        while (j!=s.size()  and  s[j]!=' ')
        {
            j++;
        }
        string tmp = s.substr(i,j-1-i+1);
        result_vector.push_back(tmp);
        i=j;

    }
    reverse(result_vector.begin(),result_vector.end());
    string result=result_vector[0];
    for (int i = 1; i < result_vector.size(); ++i) {
        result = result +' '+ result_vector[i];
    }
    return result;

}

void removeExtraSpaces(string& s)
{
    int slow = 0;
    int fast = 0;
    for(;fast<s.size();++fast)
    {
        if (s[fast] != ' ')
        {
            if (slow !=0) // ���ʺͿո�Ĵ�����˳����  �ո�+���ʣ����Ե�һ����������
            {
                s[slow] = ' '; // ������ֶ���ӿո�
                slow++;
            }
            // ����ҵ���һ�����ǿո�ģ��Ͱ������������
            while (fast<s.size() and s[fast] != ' ')
            {
                s[slow] = s[fast];
                slow++;
                fast++;
            }

        }

    }
    s.resize(slow);
}

void reverse_substr(string &s,int start,int end)
{
    while (start<end)
    {
        swap(s[start],s[end]);
        start++;
        end--;
    }
}

string reverseWords_2(string s)  // ����Ǹ���Ч�İ汾
{
    removeExtraSpaces(s);
    reverse_substr(s,0,s.size()-1);
    for (int i = 0; i < s.size();) {
        int j = i+1;
        while (j!=s.size()  and  s[j]!=' ')
        {
            j++;
        }
        reverse_substr(s,i,j-1);
        i = j+1;
    }
    return s;
}
