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

vector<string> path;
vector<vector<string>> result;

void backtracking(vector<string>& strs, vector<int> &visited, int start, unordered_map<string,vector<int>> & my_map)
{

}

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    unordered_map<string,vector<int>> my_map;
    for (int i = 0; i < strs.size(); ++i) {
        vector<int> temp(26,0);
        for (int j = 0; j < strs[i].size(); ++j) {
            temp[strs[i][j]-'a'] ++;
        }
        my_map[strs[i]] = temp;
    }
    vector<int> visited(strs.size(),0);

}

