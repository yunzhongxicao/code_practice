/*
@File  :rongyao_1.cpp
@Author:dfc
@Date  :2023/8/22  18:58
@Desc  :
*/
#include "iostream"
#include "vector"
#include "algorithm"
#include "string"

using namespace std;

bool static cmp(const string &a, const string &b)
{
    return a<b;
}

int main()
{
    int  n ;
    cin>> n;
    vector<string> origin_s_vec(n);
    for (int i = 0; i < n; ++i) {
        cin>>origin_s_vec[i];
    }

    // origin_s_vec.push_back("123456789");
    // origin_s_vec.push_back("abc");

    vector<string> s_vec;

    for (int i = 0; i < origin_s_vec.size(); ++i) {
        string s_tmp = origin_s_vec[i];

        int mod = (int )s_tmp.size() % 8;
        if ( mod != 0)
        {
            string s_add = string (8-mod,'0');
            s_tmp += s_add;
        }
        for (int j = 0; j <= (int )s_tmp.size()/8 -1  ; ++j) {
            s_vec.push_back(s_tmp.substr(j*8,8));
        }
    }

    sort(s_vec.begin(),s_vec.end(),cmp);

    for (int i = 0; i < s_vec.size(); ++i) {
        cout<<s_vec[i]<<" ";
    }

}

