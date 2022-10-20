/*
@File  :93.cpp
@Author:dfc
@Date  :2022/10/20  11:19
@Desc  : ∏¥‘≠IPµÿ÷∑
*/

#include "string"
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

vector<string> path;
vector<string> result;


void backtracking(string s ,int start_index)
{
    if (start_index==s.size())
    {
        if ((int)path.size()==4)
        {
            string tpm = path[0];
            for (int j = 1; j < path.size(); ++j) {
                tpm += '.'+path[j];
            }
            result.push_back(tpm);
            return;
        }
        else return;
    }

    for (int i = start_index; i <s.size() ; ++i) {

        string  s_sub = s.substr(start_index,i-start_index+1);
        if (stoi(s_sub)>255) break;
        path.push_back(s_sub);
        backtracking(s,i+1);
        path.pop_back();
        if (s[start_index]=='0')
            break;
    }
}

vector<string> restoreIpAddresses(string s)
{
    backtracking(s,0);
    return result;
}

int main()
{
    string s = "0000";
    restoreIpAddresses(s);
    for (int i = 0; i < result.size(); ++i) {
        cout<<result[i]<<endl;
    }
}