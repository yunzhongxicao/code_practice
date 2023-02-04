/*
@File  :844_second.cpp
@Author:dfc
@Date  :2023/2/4  11:25
@Desc  : 比较含退格的 字符串
*/
#include "iostream"
#include "string"

using namespace std;

bool backspaceCompare(string s, string t)
{
    int fast = 0,slow=0;
    while (fast<=s.size()-1)
    {
        if (s[fast]!='#')
        {
            s[slow] = s[fast];
            slow++;
            fast++;
        } else
        {
            fast++;
            if (slow>=1)
                slow--;
        }
    }
    string s_temp = s.substr(0,slow);
    fast = 0,slow=0;
    while (fast<=t.size()-1)
    {
        if (t[fast]!='#')
        {
            t[slow] = t[fast];
            slow++;
            fast++;
        } else
        {
            fast++;
            if (slow>=1)
                slow--;
        }
    }
    string t_temp = t.substr(0,slow);
    return s_temp==t_temp;
}

int main()
{
    string s="aaac";
    cout<<s.substr(0,0);
}

