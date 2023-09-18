/*
@File  :baidu_1.cpp
@Author:dfc
@Date  :2023/9/12  19:34
@Desc  :
*/
#include "iostream"

using namespace std;

void solution(int n, int m)
{
    if (n % 2== 0 and m %2 ==0)
        cout<<"No"<<endl;
    if (n%2 != 0 and m % 2 ==0)
        cout<<"Yes"<<endl;
    if (n%2 ==0 and m % 2 != 0)
        cout<<"Yes"<<endl;
    if (n%2 != 0 and m %2 != 0)
        cout<<"No"<<endl;
}

int main()
{
    int t;
    cin>>t;

    for (int i = 0; i < t; ++i) {
        int n ,m;
        cin>>n>>m;
        solution(n,m);
    }
}