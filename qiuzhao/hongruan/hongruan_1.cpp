/*
@File  :hongruan_1.cpp
@Author:dfc
@Date  :2023/8/20  10:47
@Desc  :
*/
#include "iostream"
#include "vector"
#include "stack"

using namespace std;

int main()
{
    string s;
    cin>>s;
    stack<string> my_stack;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i]!=')')
        {
            string s_t= {s[i]};
            my_stack.push(s_t);
        }

        else
        {
            int tmp =0;
            while (!my_stack.empty() and my_stack.top()!="(")
            {
                tmp += (stoi(my_stack.top()));
                my_stack.pop();
            }
            my_stack.pop();
            tmp = tmp *2;
            my_stack.push(to_string(tmp));
        }
    }
    int result = 0;
    while (!my_stack.empty())
    {
        result += stoi(my_stack.top());
        my_stack.pop();
    }
    cout<<result;
}

