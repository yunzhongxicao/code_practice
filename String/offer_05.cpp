/*
@File  :offer_05.cpp
@Author:dfc
@Date  :2022/9/2  15:15
@Desc  : Ìæ»»¿Õ¸ñ
*/
#include "string"
#include "iostream"

using namespace std;


string replaceSpace(string s);

int main()
{
    string s = "we are happy";
    string a = replaceSpace(s);
    cout<<a;
}

string replaceSpace(string s)
{
    int count = 0;
    int old_size = s.size();
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ' ')
            count++;
    }
    s.resize(s.size()+count*2);
    int new_size = s.size();
    int fast = old_size-1;
    int slow = new_size-1;
    for(;fast>=0;fast--)
    {
        if (s[fast] !=' ')
        {
            s[slow] = s[fast];
            slow--;
        } else
        {
            s[slow]='0';
            slow--;
            s[slow]='2';
            slow--;
            s[slow]='%';
            slow--;
        }
    }
    return s;
}