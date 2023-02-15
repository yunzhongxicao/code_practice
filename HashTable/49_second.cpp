/*
@File  :49_second.cpp
@Author:dfc
@Date  :2023/2/15  14:44
@Desc  : ×ÖÄ¸ÒìÎ»´Ê·Ö×é
*/
#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"
#include "algorithm"
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    unordered_map<string,vector<string>>my_map;
    vector<vector<string>>result;
    for (int i = 0; i < strs.size(); ++i) {
        string temp = strs[i];
        sort(temp.begin(),temp.end());
        my_map[temp].push_back(strs[i]);
    }
    for(auto & i : my_map)
    {
        result.push_back(i.second);
    }
    return result;
}

