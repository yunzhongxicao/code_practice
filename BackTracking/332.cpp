/*
@File  :332.cpp
@Author:dfc
@Date  :2022/10/23  15:58
@Desc  : ���°����г�
*/

#include "iostream"
#include "map"
#include "unordered_map"
#include "vector"
#include "string"

using namespace std;

vector<string> path;

unordered_map<string,map<string,int>> targets; // ���������������������

vector<string> findItinerary(vector<vector<string>>& tickets);
bool backtracking(int num_tickets,string last_from);
vector<string> findItinerary(vector<vector<string>>& tickets)
{
    for (auto ticket: tickets) {
        targets[ticket[0]][ticket[1]]++; // ������û������һ���Ļ�Ʊ ����������ʵ�ǲ����Ʊ�� �Ѵ�����0��Ϊ1
    }                                   // ���� ����һ�� ��Ʊ
    path.emplace_back("JFK");
    backtracking(tickets.size(),"JFK");
    return path;

}

bool backtracking(int num_tickets,string last_from) // ֻ��Ҫ����һ����Ҫ�ҵĳ�������������һ�㼴��
{
    if (path.size()==num_tickets+1) // ��Ʊ����+1˵���г�������
        return true;
    for (auto &target:targets[last_from]) {
        if (target.second>0)
        {
            path.push_back(target.first);
            target.second--;
            if (backtracking(num_tickets,target.first)) return true;
            path.pop_back(); // ֻ����һ��û�ҵ��Żᵯ��
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

