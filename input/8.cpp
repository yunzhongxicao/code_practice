/*
@File  :8.cpp
@Author:dfc
@Date  :2023/3/5  14:35
@Desc  :
*/
#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<string> v_str(n  );
    while (n>0)
    {
        string temp;
        cin>>temp;
        v_str[n-1] = temp;
        n--;
    }
    sort(v_str.begin(),v_str.end());
    for (int i = 0; i < v_str.size(); ++i) {
        cout<<v_str[i]<<' ';
    }
}