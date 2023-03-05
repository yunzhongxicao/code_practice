/*
@File  :10.cpp
@Author:dfc
@Date  :2023/3/5  14:47
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
    string temp="";
    char a;
    while (cin.get(a))
    {
        if (a==',') {
            v_str.push_back(temp);
            temp="";
        }
        else if (a=='\n')
        {
            v_str.push_back(temp);
            temp="";
            sort(v_str.begin(),v_str.end());
            cout<<v_str[0];
            for (int i = 1; i < v_str.size(); ++i) {
                cout<<","<<v_str[i];
            }
            v_str.clear();
            cout<<endl;
        }
        else
        {
            temp += a;
        }
    }
}