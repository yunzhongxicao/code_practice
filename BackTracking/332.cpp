/*
@File  :332.cpp
@Author:dfc
@Date  :2022/10/23  15:58
@Desc  : 重新安排行程
*/

#include "iostream"
#include "map"
#include "unordered_map"
#include "vector"
#include "string"

using namespace std;

vector<string> path;

unordered_map<string,map<string,int>> targets; // 【出发，【到达，次数】】

vector<string> findItinerary(vector<vector<string>>& tickets);
bool backtracking(int num_tickets,string last_from);
vector<string> findItinerary(vector<vector<string>>& tickets)
{
    for (auto ticket: tickets) {
        targets[ticket[0]][ticket[1]]++; // 由于是没有两张一样的机票 所以这里其实是插入机票后 把次数从0改为1
    }                                   // 错了 会有一样 机票
    path.emplace_back("JFK");
    backtracking(tickets.size(),"JFK");
    return path;

}

bool backtracking(int num_tickets,string last_from) // 只需要把上一层需要找的出发机场传到下一层即可
{
    if (path.size()==num_tickets+1) // 机票数量+1说明行程满足了
        return true;
    for (auto &target:targets[last_from]) {
        if (target.second>0)
        {
            path.push_back(target.first);
            target.second--;
            if (backtracking(num_tickets,target.first)) return true;
            path.pop_back(); // 只有下一层没找到才会弹出
            target.second++;
        }
    }
    return false;
}

int main()
{
    vector<vector<string>> tickets = {{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}};
//    vector<vector<string>> tickets = {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
    findItinerary(tickets);
    for ( const auto& s:path) {
        cout<<s<<endl;
    }
}

