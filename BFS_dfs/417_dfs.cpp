/*
@File  :417_dfs.cpp
@Author:dfc
@Date  :2023/3/24  19:44
@Desc  :
*/
#include "iostream"
#include "vector"

using namespace std;

vector<vector<int>> directions= {{-1,0},{1,0},{0,-1},{0,1}};
void dfs(vector<vector<int>> &heights,int x1, int x2, vector<vector<int>>&state )
{
    state[x1][x2] =1;
    for (int i = 0; i < 4; ++i) {
        int next_x1 = x1 + directions[i][0];
        int next_x2 = x2 + directions[i][1];
        if (next_x1<0 or next_x1>heights.size()-1 or next_x2<0 or next_x2>heights[0].size()-1) continue;
        if (heights[next_x1][next_x2]>= heights[x1][x2] and state[next_x1][next_x2]==0)
            dfs(heights,next_x1,next_x2,state);
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
{
    vector<vector<int>> pacific(heights.size(),vector<int>(heights[0].size(),0));
    vector<vector<int>> atlantic(heights.size(),vector<int>(heights[0].size(),0));
    for (int i = 0; i < heights.size(); ++i) {
        dfs(heights,i,0,pacific);
        dfs(heights,i,heights[0].size()-1,atlantic);
    }
    for (int j = 0; j < heights[0].size(); ++j) {
        dfs(heights,0,j,pacific);
        dfs(heights,heights.size()-1,j,atlantic);
    }
    vector<vector<int>>result;
    for (int i = 0; i < heights.size(); ++i) {
        for (int j = 0; j < heights[0].size(); ++j) {
            if (pacific[i][j]==1 and atlantic[i][j]==1)
            {
                result.push_back(vector<int>{i,j});
            }
        }
    }
    return result;
}

int main()
{
//    vector<vector<int>>heights = {{1,2,4,3,5},
//                                  {3,5,3,4,8},
////                                  {2,4,5,3,1},
////                                  {6,7,1,4,5},
////                                  {5,1,1,2,4}
//    };
    vector<vector<int>> heights = {{1,2},{3,2}};
    vector<vector<int>> result = pacificAtlantic(heights);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[0].size(); ++j) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}