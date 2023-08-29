/*
@File  :meituan_4.cpp
@Author:dfc
@Date  :2023/8/26  10:27
@Desc  :
*/
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

bool solution(vector<int>&a, vector<int>&b, int m)
{
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end());
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] + b[i] >=1 and a[i] + b[i] <=m)
            continue;
        else
            return false;
    }
    return true;
}

int main()
{
    int q;
    cin>>q;
    for (int i = 0; i < q; ++i) {
        int n,m;
        cin>>n>>m;
        vector<int> a(n);
        for (int j = 0; j < n; ++j) {
            cin>>a[j];
        }
        vector<int>b(n);
        for (int j = 0; j < n; ++j) {
            cin>>b[j];
        }
        if (solution(a,b,m)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}

