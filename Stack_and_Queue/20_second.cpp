/*
@File  :20_second.cpp
@Author:dfc
@Date  :2023/2/23  11:07
@Desc  : ��Ч������
*/
#include "iostream"
#include "string"
#include "stack"
using namespace std;

bool isValid(string s)
{
    stack<char> my_stack;
    for (int i = 0; i < s.size(); ++i) {
        // ������ȷ ��������ջ ������ֻ�����ջ ������ջ����
        if (s[i] == '(') my_stack.push(')');
        else if (s[i] == '{') my_stack.push('}');
        else if (s[i] == '[') my_stack.push(']');

        else if (my_stack.empty() or my_stack.top() != s[i])
            return false;
        else my_stack.pop(); // ��ȵ���
    }
    return my_stack.empty();
}


