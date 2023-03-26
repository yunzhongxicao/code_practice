/*
@File  :offer_62.cpp
@Author:dfc
@Date  :2023/3/26  17:19
@Desc  :
*/

#include "iostream"
#include "vector"

using namespace std;
int lastRemaining(int n, int m)
{
    vector<int>next(n);
    for (int i = 0; i < n; ++i) {
        next[i] = (i+1) % n;
    }
    if (n==1) return 0;
    if (m==1) return n-1;
    int count = 2;
    int cur = 1;
    int pre = 0;
    while (next[cur]!=cur)
    {
        if (count<m)
        {
            pre = cur;
            cur = next[cur];
            count++;
        }
        else
        {
            cur = next[cur];
            next[pre] = cur;
            count=1;
        }
    }
    return cur;
}

int main()
{
    cout<<lastRemaining(10,17);
}
