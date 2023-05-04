/*
@File  :offer_2_042.cpp
@Author:dfc
@Date  :2023/5/3  19:55
@Desc  :
*/
#include "iostream"
#include "queue"
using namespace std;

class RecentCounter {
public:
    queue<int> times;
    RecentCounter() {

    }

    int ping(int t) {
        int t_start = t-3000;
        while (!times.empty())
        {
            if (times.front()<t_start)
                times.pop();
            else
                break;
        }
        times.push(t);
        return times.size();
    }
};

int main()
{
    RecentCounter *obj = new RecentCounter();
    cout<< obj->ping(642)<<" ";
    cout<< obj->ping(1849)<<" ";
    cout<< obj->ping(4921)<<" ";

    cout<< obj->ping(5936)<<" ";
    cout<< obj->ping(5957)<<" ";

}