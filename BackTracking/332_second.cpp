/*
@File  :332_second.cpp
@Author:dfc
@Date  :2023/3/25  10:29
@Desc  :
*/
#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"
#include "map"
using namespace std;
unordered_map<string,map<string,int>> my_map;
vector<string> path;
// vector<vector<string>> result;

bool dfs(vector<vector<string>> &tickets,const string& cur)
{
    path.push_back(cur);
    if (path.size()==tickets.size()+1)
    {
        // result.push_back(path);
        return true;
    }
    // map<string,int> temp = my_map[cur];
    for(auto &iter:my_map[cur])
    {
        if (iter.second>0)
        {
            iter.second--;
            bool flag = dfs(tickets,iter.first);
            if (flag)
                return true;
            iter.second++;
            path.pop_back();
        }
    }
    return false;
}

vector<string> findItinerary(vector<vector<string>>& tickets)
{

    for (int i = 0; i < tickets.size(); ++i) {
        // map<string,int> temp;
        // temp[tickets[i][1]]++;
        my_map[tickets[i][0]][tickets[i][1]]++;
    }
    dfs(tickets,"JFK");
    return path;
}

int main()
{
    // vector<vector<string>> tickets = {{"JFK","SFO"},
    //                                   {"JFK","ATL"},
    //                                   {"SFO","ATL"},
    //                                   {"ATL","JFK"},
    //                                   {"ATL","SFO"}};
    vector<vector<string>> tickets = {{"JFK","KUL"},
                                      {"JFK","NRT"},
                                      {"KUL","JFK"}};
    findItinerary(tickets);
    for (int i = 0; i < result[0].size(); ++i) {
        cout<<result[0][i]<<"  ";
    }
}

