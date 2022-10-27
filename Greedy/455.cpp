/*
@File  :455.cpp
@Author:dfc
@Date  :2022/10/26  11:56
@Desc  : 分发饼干
*/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

// g是胃口 s是饼干尺寸
int findContentChildren(vector<int>& g, vector<int>& s)
{
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int num=0;
    int index_g=(int)g.size()-1;
    for (int i = (int)s.size()-1; i >=0 and index_g>=0; i--) { // 其实遍历g更合理 找到了就自然往下 找不到就说明没有 依然往下
        if (s[i]>=g[index_g])
        {
            index_g--;
            num++;
        }
        else
        {
            index_g--;
            i++;
        }
    }
    return num;
}

int main()
{
    vector<int> g={1,2};
    vector<int> s={1,2,3};
     int result= findContentChildren(g,s);
     cout<<result;
}