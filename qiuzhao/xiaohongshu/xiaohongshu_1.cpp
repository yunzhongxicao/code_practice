/*
@File  :xiaohongshu_1.cpp
@Author:dfc
@Date  :2023/7/23  19:34
@Desc  :
*/
#include "iostream"
#include "vector"

using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;
    int result = 0;
    for (int i = 1; i <=n ; ++i) {
        result += i *k;
    }
    cout<<result;
    return 0 ;
}

