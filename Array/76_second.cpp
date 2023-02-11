/*
@File  :76_second.cpp
@Author:dfc
@Date  :2023/2/11  10:30
@Desc  : ��С�����Ӵ�
*/
#include "string"
#include "iostream"
#include "vector"
#include "unordered_map"
using namespace std;

unordered_map<char,int>ori, cnt;

bool check()
{
    for(auto &p:ori)
    {
        if (cnt[p.first] <p.second  ) // �ڵ�ǰ�Ĺ�ϣ��ȥ��ԭʼ���ַ�
            return false;
    }
    return true;
}

string minWindow(string s, string t)
{
    for (int i = 0; i < t.size()     ; ++i) {
        ori[t[i]]++;
    }
    int start =  0, end=0;
    int result =s.size()+1;
    int left_index=0;
    string s_result="";
    while (end<s.size())
    {
        // cnt[s[end]]++;
        if (ori.find(s[end]) != ori.end())  // �ڶ�����ϣ��ֻ��Ҫά����ǰ������ t���ַ��ĸ��� �޹ص��ַ�����Ҫͳ�ƽ���
            cnt[s[end]]++;

        while (check())
        {
            int temp = end-start+1;
            if(temp<=result)
            {
                result = temp;
                left_index = start;
                // s_result = s.substr(start,temp); // ÿ�ζ���substr�ᳬʱ��
            }
            if (ori.find(s[start]) != ori.end())
                cnt[s[start]]--;
            // cnt[s[start]]--; // �ڶ�����ϣ��ֻ��Ҫά����ǰ������ t���ַ��ĸ��� �޹ص��ַ�����Ҫͳ�ƽ���
            start++;
        }
        end++;
    }
    if (result==s.size()+1) return "";
    s_result = s.substr(left_index,result);
    return s_result;
}

