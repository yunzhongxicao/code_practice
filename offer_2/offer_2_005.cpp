/*
@File  :offer_2_005.cpp
@Author:dfc
@Date  :2023/2/9  12:53
@Desc  :
*/
#include "iostream"
#include "vector"
#include "string"

using namespace std;

int maxProduct(vector<string>& words)
{
    vector<int>count(words.size(),0);
    for (int i = 0; i < words.size(); ++i) {
        for (int j = 0; j < words[i].size(); ++j) {
            count[i] = (count[i] | (1<<(words[i][j]-'a')));
        }
    }
    int result=0;
    for (int i = 0; i < words.size(); ++i) {
        for (int j = 0; j < words.size(); ++j) {
            if ((count[i] &  count[j])==0)
            {
                result = max(result,(int)(words[i].size() * words[j].size()));
            }
        }
    }
    return result;
}

