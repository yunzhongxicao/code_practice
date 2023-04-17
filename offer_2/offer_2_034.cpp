/*
@File  :offer_2_034.cpp
@Author:dfc
@Date  :2023/4/17  15:57
@Desc  :
*/
#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"

using namespace std;

bool isAlienSorted(vector<string>& words, string order)
{
    unordered_map<char,int> my_map;
    for (int i = 0; i < order.size(); ++i) {
        my_map[order[i]] = i+1;
    }
    for (int i = 1; i < words.size(); ++i) {
        int j = 0;
        int count = 0;
        while (j<min(words[i-1].size(),words[i].size()))
        {
            if (my_map[words[i-1][j]] <  my_map[words[i][j]])
                break;
            else if (my_map[words[i-1][j]] ==  my_map[words[i][j]])
            {
                j++;
                count++;
            }
            else
                return false;
        }
        if (count== min(words[i-1].size(),words[i].size()) and words[i-1].size()>words[i].size())
            return false;
    }
    return true;
}

