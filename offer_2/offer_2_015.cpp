/*
@File  :offer_2_015.cpp
@Author:dfc
@Date  :2023/2/22  10:59
@Desc  : 字符串中的所有变位词
*/
#include "iostream"
#include "vector"
#include "string"

using namespace std;

/*vector<int> findAnagrams(string s, string p) // 滑动窗口
{
    vector<int> result;
    if (p.size()>s.size()) return result;
    vector<int>count1(26,0),count2(26,0);
    for (int i = 0; i < p.size(); ++i) {
        count2[p[i]-'a']++;
    }
    for (int i = 0; i < p.size(); ++i) {
        count1[s[i]-'a']++;
    }
    if (count1 == count2) result.push_back(0);
    for (int i = 1; i +p.size()-1<=s.size()-1 ; ++i) {
        count1[s[i-1]-'a'] --;
        count1[s[i+p.size()-1]-'a']++;
        if (count1==count2) result.push_back(i);
    }
    return result;
}*/

vector<int> findAnagrams(string s, string p)
{
    vector<int> result;
    if (p.size()>s.size()) return result;
    vector<int> count(26,0);  // count记录的是s抛掉p后的数量
    for (int i = 0; i < p.size(); ++i) {
        count[s[i]-'a']++;
        count[p[i]-'a']--;
    }
    int diff = 0; // diff记录的是不同的字符的种类个数  不是不同的总数  是种类数  所以只有在某个种类变为0的时候才会改变
    for (int i = 0; i < count.size(); ++i) {
        if (count[i] !=0 ) diff++;
    }
    if (diff==0) result.push_back(0);
    for (int i = 1; i +p.size()-1<=s.size()-1; ++i) {
        int x= s[i-1]-'a', y= s[i+p.size()-1]-'a';
        if (count[x]==1)
            diff--;
        else if (count[x]==0)
            diff++;
        count[x]--;
        if (count[y]==0)
            diff++;
        else if (count[y]==-1)
            diff--;
        count[y] ++;
        if (diff==0) result.push_back(i);
    }
    return result;
}

