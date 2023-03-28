/*
@File  :two.cpp
@Author:dfc
@Date  :2023/3/26  20:05
@Desc  :
*/

#include "iostream"
#include "vector"
#include "string"
using namespace std;

string path;
vector<string> result;
vector<int>used(26,0);

void backtracking(vector<string>&s_vec, int index)
{
    if (path.size()==s_vec.size())
    {
        result.push_back(path);
        return;
    }
    string cur_str = s_vec[index];
    vector<int>used_cur(26,0);
    for (int i = 0; i < cur_str.size(); ++i) {
        if (used[cur_str[i]-'a']==1)
            continue;
        if (used_cur[cur_str[i]-'a'] == 1)
            continue;
        path.push_back(cur_str[i]);
        used[cur_str[i]-'a'] =1;
        used_cur[cur_str[i]-'a'] = 1;
        backtracking(s_vec,index+1);
        path.pop_back();
        used[cur_str[i]-'a'] =0;
    }
}

int main()
{
    int N;
    cin>>N;
    vector<string>s_vec(N);
    for (int i = 0; i < N; ++i) {
        cin>>s_vec[i];
    }
    backtracking(s_vec,0);
    // for (int i = 0; i < result.size()   ; ++i) {
    //     cout<<result[i]<<" ";
    // }
    cout<<result.size();
}
