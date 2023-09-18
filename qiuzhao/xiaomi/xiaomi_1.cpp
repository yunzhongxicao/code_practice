/*
@File  :xiaomi_1.cpp
@Author:dfc
@Date  :2023/9/2  16:28
@Desc  :
*/

#include "iostream"
#include "vector"
#include "unordered_map"
#include "map"
using namespace std;



int main()
{
    int n=3;
    cin>>n;
    vector<vector<int>> graph(n,vector<int>(4,0) );
    // graph[0]= vector<int>{250 ,250 ,250 ,250};
    // graph[1] = vector<int>{156,  201,  205 ,400};
    // graph[2] = vector<int>{205 , 190, 100,  250};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin>>graph[i][j];
        }
    }
    map<int  ,int> my_map;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            my_map[graph[i][0]+graph[j][1]]++;
        }
    }
    int result = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (my_map.find(1000-graph[i][2]-graph[j][3]) != my_map.end())
                result += my_map[1000-graph[i][2]-graph[j][3]];
        }
    }
    cout<<result;
}
