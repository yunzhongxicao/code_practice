/*
@File  :rongyao_2.cpp
@Author:dfc
@Date  :2023/8/22  19:31
@Desc  :
*/
#include "iostream"
#include "cmath"
#include "vector"
#include "algorithm"

using namespace std;

struct position{
    int x;
    int y;
};

int compute_distance(position & A, position &B)
{
    return sqrt((A.x - B.x) * (A.x - B.x)  + (A.y - B.y) * (A.y - B.y));
}

vector<int> result_vec;
int path =0;
int node_num = 0;
void dfs(int index,vector<position> &pos_vec,vector<vector<int>> &graph, vector<int> & visited)
{
    if (node_num==5)
    {
        result_vec.push_back(path + graph[index][0]);
        return;
    }
    for(int i =0; i<6;i++)
    {
        if (i==0 or i==index) continue;
        if (visited[i] == 1) continue;
        path += graph[index][i];
        visited[i] = 1;
        node_num ++;
        dfs(i,pos_vec,graph,visited);

        path -= graph[index][i];
        visited[i] = 0;
        node_num--;
    }
}

int main()
{
    position origin_node ;
    origin_node.x   = 0;
    origin_node.y =0;

    vector<position> pos_vec;
    pos_vec.push_back(origin_node);
    for (int i = 0; i < 5; ++i) {
        position tmp;
        cin>>tmp.x>>tmp.y;
        pos_vec.push_back(tmp);
    }
    vector<vector<int>> graph(6, vector<int>(6,0));
    for (int i = 0; i < 6; ++i) {
        for (int j = i; j <6 ; ++j) {
            int dis = compute_distance(pos_vec[i], pos_vec[j]);
            graph[i][j] = dis;
            graph[j][i] = dis;
        }
    }
    vector<int> visited(6,0);
    dfs(0,pos_vec,graph,visited);
    // for (int i = 0; i < result_vec.size(); ++i) {
    //     cout<<
    // }
    sort(result_vec.begin(),result_vec.end());
    for (int i = 0; i < result_vec.size(); ++i) {
        cout<<result_vec[i]<<" ";
    }
    cout<<endl;
    cout<<result_vec[0]<<endl;
}
