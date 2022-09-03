/*
@File  :151.cpp
@Author:dfc
@Date  :2022/9/2  15:45
@Desc  :反转字符串中的单词
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

string reverseWords_1(string s) // 这个是没看解析前自己写的版本，用到了切片和反转两个函数，同时空间复杂度高
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
            if (slow !=0) // 单词和空格的处理子顺序是  空格+单词，所以第一个单独讨论
            {
                s[slow] = ' '; // 找完后手动添加空格
                slow++;
            }
            // 如果找到了一个不是空格的，就把这个单词找完
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

string reverseWords_2(string s)  // 这个是更高效的版本
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
