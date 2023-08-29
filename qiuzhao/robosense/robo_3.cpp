/*
@File  :robo_3.cpp
@Author:dfc
@Date  :2023/8/26  15:55
@Desc  :
*/
#include "iostream"
#include "vector"
#include "string"

using namespace std;

#include "iostream"
#include "vector"
#include "queue"

using namespace std;
int count;
bool flag = false;
vector<vector<int>>directions= {{-1,0},{1,0},{0,-1},{0,1}};
int start_x1, start_x2, end_x1, end_x2;

void bfs(vector<string> &grid, int x1, int x2, vector<vector<int>> &visited)
{
    visited[x1][x2] = 1;
    // count++;
    pair<pair<int,int>, int> my_pair0= {{x1, x2}, 0};
    queue<pair<pair<int,int>, int>> my_queue;
    my_queue.push(my_pair0);
    while (!my_queue.empty())
    {
        pair<pair<int,int>, int> temp = my_queue.front();
        my_queue.pop();
        int current_l = temp.second;
        for (int i = 0; i < 4; ++i) {
            int next_x1 = temp.first.first+directions[i][0];
            int next_x2 = temp.first.second +  directions[i][1];
            if (next_x1<0 or next_x1>grid.size()-1 or next_x2<0 or next_x2>grid[0].size()-1) continue;
            if (grid[next_x1][next_x2]=='.' and visited[next_x1][next_x2]==0) // 每次加入的时候就处理了
            {
                // cout<< next_x1<<" "<<next_x2<<endl;
                pair<pair<int,int>, int> my_pair_tmp= {{next_x1, next_x2}, current_l+1};
                my_queue.push(my_pair_tmp);
                visited[next_x1][next_x2] = 1;
                // count++;
                if (next_x1==end_x1 and next_x2==end_x2)
                {
                    flag = true;
                    count = my_pair_tmp.second;
                    return;
                }
            }
        }
    }
}

int main()
{
    int n, m;
    cin>>n>>m;

    cin>>start_x1>>start_x2>>end_x1>>end_x2;
    start_x1--; start_x2--; end_x1--; end_x2--;

    // int n = 5, m =5;
    start_x1 = 0; start_x2 =0; end_x1= 4;  end_x2=4;
    vector<string> grid;
    for (int i = 0; i < n; ++i) {
        cin>>grid[i];
    }

    // grid.push_back(".....");
    // grid.push_back("****.");
    // grid.push_back(".....");
    // grid.push_back("**.**");
    // grid.push_back(".....");

    vector<vector<int>> visited(n, vector<int>(m,0));
    bfs(grid,start_x1,start_x2,visited);
    if (flag) cout<<count<<endl;
    else cout<<-1<<endl;
}

