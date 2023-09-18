/*
@File  :baidu_3.cpp
@Author:dfc
@Date  :2023/9/12  20:04
@Desc  :
*/
#include "iostream"
#include "vector"

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> yuzhi(n,0);
    for (int i = 0; i < n; ++i) {
        cin>>yuzhi[i];
    }
//    vector<int> diff(n,0);
    vector<int> ang(n,0);
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin>>l>>r;
        for (int j = l-1; j <=r-1 ; ++j) {
            ang[j] += 1;
            if (ang[j]>yuzhi[j])
            {
                cout<<i;
                break;
            }
        }
    }
    cout<<m;
}