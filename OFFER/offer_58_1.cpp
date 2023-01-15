/*
@File  :offer_58_1.cpp
@Author:dfc
@Date  :2023/1/15  11:51
@Desc  : ��ת����˳��
*/
#include "iostream"
#include "vector"
#include "string"
using namespace std;

/*string reverseWords(string s)
{
    int start =s.size()-1;
    int end;
    vector<string> word_list;
    while (start>=0)
    {
        while (start>=0 and  s[start]==' ') // �ҵ��ʵĽ�����
            start--;
        if (start<0 ) break;// ���start����-1 ���ܰ�endҲ��ֵΪ-1
        end =start;
        while (start>=0 and s[start]!=' ') // ���Ĺ����ֿ��ܵ�-1�� �ҵ��ʵ���ʼ��-1
            start--;

        word_list.push_back(s.substr(start+1,end-start));
    }
    if (word_list.empty()) return "";
    string result=word_list[0];
    for(int i=1; i<word_list.size();++i)
    {
        result+= (" "+word_list[i]);
    }
    return result;
}*/

string reverseWords(string s) // �Ż�һ��  ����vector
{
    int start =s.size()-1;
    int end;
    vector<string> word_list;
    string result;
    while (start>=0)
    {
        while (start>=0 and  s[start]==' ') // �ҵ��ʵĽ�����
            start--;
        if (start<0 ) break;// ���start����-1 ���ܰ�endҲ��ֵΪ-1
        end =start;
        while (start>=0 and s[start]!=' ') // ���Ĺ����ֿ��ܵ�-1�� �ҵ��ʵ���ʼ��-1
            start--;

        result +=(s.substr(start+1,end-start) +" ");
    }
    if (!result.empty()) result.pop_back();
    return result;
}

int main()
{
    string s = "  hello world!  ";
    cout<< reverseWords(s);
}

