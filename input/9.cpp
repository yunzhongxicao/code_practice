/*
@File  :9.cpp
@Author:dfc
@Date  :2023/3/5  14:41
@Desc  :
*/
#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
using namespace std;

int main()
{
    vector<string> v_str;
    string temp;
    while (cin>>temp)
    {
        v_str.push_back(temp);
        if (cin.get()=='\n')
        {
            sort(v_str.begin(),v_str.end());
            for (int i = 0; i < v_str.size(); ++i) {
                cout<<v_str[i]<<' ';
            }
            v_str.clear();
            cout<<endl;
        }
    }
}