#include <iostream>
#include "vector"
#include "unordered_set"
#include "unordered_map"
using namespace std;


int solution(vector<vector<int>>&order, int n, int m)
{
    unordered_map<int,int>my_map;
    int result=0; // 社团数量
    int count=0; // 学生数量
    for (int i = 0; i < order.size(); ++i) {
        int temp0 = order[i][0], temp1 = order[i][1];
        if(my_map.find(temp0)==my_map.end() and my_map.find(temp1)==my_map.end())
        {
            result++;
            my_map[temp0]++;
            my_map[temp1]++;
            count +=2;
        }
        else
        {
            if (my_map.find(temp0)!=my_map.end()and my_map.find(temp1)==my_map.end()) // 有一个不在 社团不需要添加 学生增加+1
            {
                count++;
                my_map[temp1]++;
            }
            else if (my_map.find(temp0)==my_map.end()and my_map.find(temp1)!=my_map.end())
            {
                count++;
                my_map[temp0]++;
            }
        }
    }
    // count 和 n之间的差值
    // result + (n-count)
}

int main() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>>order(m,vector<int>(2,0));
    for (int i = 0; i < m; ++i) {
        cin>>order[i][0]>>order[i][1];
    }
}
