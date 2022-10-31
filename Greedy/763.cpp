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
/*
vector<int> partitionLabels(string s)
{
    vector<int> index(26,-1)  ;
    for (int i = 0; i < s.size(); ++i) { // 找到每个字符的最远位置
        int tmp = s[i]-'a';
        index[tmp] = i;
    }
    int max_index=index[s[0]-'a']; // 每一段的最远距离
    vector<int> result;
    int num =0;
    for (int i = 0; i < s.size(); ++i) {
        int tmp = s[i] - 'a';
        if (i > max_index) // 每次只有找到当前最大范围的下一个点 说明上一段结束了  然后压入结果 然后重新计算下一个最大范围
        {
            result.push_back(num);
            num= 1;
            max_index = index[tmp];
        }
        else
        {
            num++;
            max_index = max(max_index,index[tmp]);
        }
    }
    result.push_back(num); // 最后一段由于无法找到最远距离的下一个点 所以要手动压入结果
    return result;
}*/



vector<int> partitionLabels(string s)
{
    vector<int> index(26,-1)  ;
    for (int i = 0; i < s.size(); ++i) { // 找到每个字符的最远位置
        int tmp = s[i]-'a';
        index[tmp] = i;
    }
    int max_index=-1; // 每一段的最远距离
    vector<int> result;
    int num =0;
    for (int i = 0; i < s.size(); ++i) {
        int tmp = s[i] - 'a';
        max_index = max(max_index,index[tmp]); // 每次先算一下当前片段的最远距离 然后再判断是否片段结束
        if (i == max_index) // 找到相等的 肯定是结束了 此时不用重置max_index 因为下一次在前面肯定能重置，下一次的index一定比现在大
        {
            num++;
            result.push_back(num);
            num= 0;
        }
        else
        {
            num++;
        }
    }
    return result;
}

int main()
{
    string s =  "ababcbacadefegdehijhklij";
//    string s = "caedbdedda";
    vector<int> result = partitionLabels(s);

    for (int i = 0; i < result.size(); ++i) {
        cout<< result[i] << " ";
    }
}

