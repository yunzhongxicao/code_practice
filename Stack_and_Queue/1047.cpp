/*
@File  :1047.cpp
@Author:dfc
@Date  :2022/9/5  10:27
@Desc  :删除字符串中所有相邻重复项
*/

#include "string"
#include "stack"
#include "algorithm"

#include "iostream"
using namespace std;

string removeDuplicates(string s);


int main()
{
    string s = "abbaca";
    string b = removeDuplicates(s);
    cout<<b;
}

string removeDuplicates(string s)
{
    stack<char> my_stack;
    for (int i = 0; i < s.size(); ++i) {
        if (my_stack.empty())
            my_stack.push(s[i]);
        else
        {
            if (s[i] == my_stack.top())
                my_stack.pop();
            else
            {
                my_stack.push(s[i]);
            }
        }
    }

    string result;
    while (!my_stack.empty())
    {
        // result =result+my_stack.top(); 这种写法会分配不必要的临时内存，大容量下会报错
        result += my_stack.top();
        my_stack.pop();
    }
    reverse(result.begin(),result.end());
    return result;

}
