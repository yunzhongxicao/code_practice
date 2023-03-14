/*
@File  :1.cpp
@Author:dfc
@Date  :2023/3/13  20:18
@Desc  :
*/
#include <bits/stdc++.h>
using namespace std;

void try_fun(string& str,vector<int>  mapping){
    for (int i=0;i<str.size();i++) {
        if (str[i] == 'B') mapping[0]--;
        else if (str[i]  == 'a') mapping[1]--;
        else if (str[i]  == 'i') mapping[2]--;
        else if (str[i]  == 'd') mapping[3]--;
        else if (str[i] == 'u') mapping[4]--;
        else mapping[5]--;
    }
    bool flag = true;
    for (auto i:mapping) {
        if (i!=0) {
            flag = false;
            break;
        }
    }
    if (flag) cout<<"Yes";
    else cout<<"No";
}
int main() {
    int t;
    cin >> t;
    vector<int> mapping(6, 1);
    mapping[5]=0;
    vector<string> vec_str;
    int num =t;
    string temp;
    while (num>0)
    {
        cin >> temp;
        vec_str.push_back(temp);
        num--;
    }
    for(auto i:vec_str){
        try_fun(i,mapping);
    }
    return 0;
}

