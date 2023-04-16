/*
@File  :offer_2_033.cpp
@Author:dfc
@Date  :2023/4/16  16:37
@Desc  :
*/
#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"

using namespace std;


vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    unordered_map<string ,vector<string>> my_map;
    for (int i = 0; i < strs.size(); ++i) {
        string temp(26,'0');
        for (int j = 0; j < strs[i].size(); ++j) {
            temp[strs[i][j]-'a']++;
        }
        my_map[temp].push_back(strs[i]);
    }
    vector<vector<string>> result;
    for(auto iter:my_map)
    {
        result.push_back(iter.second);
    }

    return result;
}

