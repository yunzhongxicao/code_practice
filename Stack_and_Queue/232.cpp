/*
@File  :232.cpp
@Author:dfc
@Date  :2022/9/4  11:33
@Desc  :
*/
#include "stack"
#include "iostream"
using namespace std;

class MyQueue {
public:
    stack<int> stack_in;
    stack<int> stack_out;
    MyQueue() {

    }

    void push(int x) {
        stack_in.push(x);
    }

    int pop() {
        if (stack_out.empty())  // ע�� ���������
                                // ��Ϊһ�ε����ǰ�in������Ԫ�ص��룬���Զ���Ҫ���Ļ�Ҳ���Ȱ���һ�ε���ĳ����ٵ���
                                // �����û���꣬˵��out�����˳���Ǹ�queueһ���ģ�����ֱ�Ӵ�out������ų�
        {
            while (!stack_in.empty())
            {
                int tmp = stack_in.top();
                stack_out.push(tmp);
                stack_in.pop();
            }
        }

        int result = stack_out.top();
        stack_out.pop();
        return result;
    }

    int peek() {
        int result = this->pop();
        stack_out.push(result);
        cout<<result<<endl;
        return result;

    }

    bool empty() {
        bool a = stack_in.empty() && stack_out.empty();
        cout<<a<<endl;
        return a;
    }
};

int main()
{
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    obj->peek();
    obj->pop();
    obj->empty();
}



