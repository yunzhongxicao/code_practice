/*
@File  :406.cpp
@Author:dfc
@Date  :2022/10/31  11:47
@Desc  :根据身高重建队列
*/
#include "vector"
#include "iostream"
#include "algorithm"
#include "list"
using namespace std;

bool static cmp(const vector<int> &a, const vector<int> &b)
{
    bool flag;
    if (a[0]>b[0])
        return true;
    else if (a[0]<b[0]) return false;
    else if(a[0] == b[0])
    {
        if (a[1]<b[1])
            return true;
        else return false;
    }
}


vector<vector<int>> reconstructQueue(vector<vector<int>>& people);


vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
{
    sort(people.begin(),people.end(),cmp);
    vector<vector<int>> result;
    for (int i = 0; i < people.size(); ++i) {
        result.insert(result.begin()+people[i][1],people[i]);
    }
    return result;

}



int main()

{
    vector<vector<int>> people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    vector<vector<int>> result =  reconstructQueue(people);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }

    // sort(people.begin(),people.end(),cmp);
    // for (int i = 0; i < people.size(); ++i) {
    //     for (int j = 0; j < people[i].size(); ++j) {
    //         cout<<people[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}