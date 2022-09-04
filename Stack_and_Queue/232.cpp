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
        if (stack_out.empty())  // 注意 这里很巧妙
                                // 因为一次导入是把in的所有元素导入，所以队列要出的话也是先把上一次导入的出完再导入
                                // 如果还没出完，说明out里面的顺序还是跟queue一样的，可以直接从out里面接着出
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



