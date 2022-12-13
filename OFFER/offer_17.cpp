/*
@File  :offer_17.cpp
@Author:dfc
@Date  :2022/12/13  10:25
@Desc  :
*/
#include "iostream"
#include "vector"
#include "string"
#include "cmath"
using namespace std;

/*vector<int> printNumbers(int n) // 这是不考虑大数越界的情况
{
    int max_value = pow(10,n) -1;
    vector<int> result;
    for (int i = 1; i <=max_value ; ++i) {
        result.push_back(i);
    }
    return result;
}*/

string path;
vector<int> result;

void backtracking(int n)
{
    if (path.size()==n)
    {
        if (path[0]=='0')
        {
            int ptr = 0;
            while (ptr<=path.size()-1 and path[ptr]=='0')
            {
                ptr++;
            }
//            if (ptr==path.size()) result.push_back(0); // 错了 0不应该push
//            else result.push_back(stoi(path.substr(ptr)));

            if (ptr !=path.size()) result.push_back(stoi(path.substr(ptr)));
        }
        else result.push_back(stoi(path));
        return;
    }
    for (int i = 0; i < 10; ++i) {
        char tmp = i +'0';
        path.push_back(tmp);
        backtracking(n);
        path.pop_back();
    }
}

vector<int> printNumbers(int n)
{
    backtracking(n);
    return result;
}

