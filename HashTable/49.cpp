/*
@File  :49.cpp
@Author:dfc
@Date  :2022/8/28  18:51
@Desc  : ×ÖÄ¸ÒìÎ»´Ê·Ö×é
*/

#include "map"
#include "string"
#include "iostream"
#include "vector"
#include <algorithm>

using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs);

int main()
{
    vector<string> a = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>>b = groupAnagrams(a);
    for (int i = 0; i < b.size(); ++i) {
        for (int j = 0; j < b[i].size(); ++j) {
            cout<<b[i][j]<<"  ";
        }
        cout<<endl;
    }
}

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    map<string,vector<string>> myMap;

    for (int i = 0; i < strs.size(); ++i) {
        string tmp = strs[i];
        sort(tmp.begin(),tmp.end());
        myMap[tmp].push_back(strs[i]);
    }
    vector<vector<string>>result;
    for (auto i = myMap.begin() ; i !=myMap.end() ; ++i) {
        result.push_back(i->second);
    }
    return result;
}



