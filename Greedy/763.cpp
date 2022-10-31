/*
@File  :763.cpp
@Author:dfc
@Date  :2022/10/31  15:17
@Desc  : 划分字母区间
*/
#include "iostream"
#include "string"
#include "vector"

using namespace std;

vector<int> partitionLabels(string s)
{
    int index[26]={-1};
    for (int i = 0; i < s.size(); ++i) { // 找到每个字符的最远位置
        int tmp = s[i]-'a';
        index[tmp] = i;
    }
    int max_index=-1; // 每一段的最远距离
    vector<int> result;
    int num =1;
    for (int i = 1; i < s.size(); ++i) {
        int tmp = s[i] - 'a';
        if (i > max_index)
        {
            result.push_back(num);
            num= 0;
            max_index = index[tmp];
        }
        else
        {
            num++;
            max_index = max(max_index,index[tmp]);
        }
    }
    return result;
}


