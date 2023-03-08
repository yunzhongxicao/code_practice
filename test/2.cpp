/*
@File  :2.cpp
@Author:dfc
@Date  :2023/3/7  19:28
@Desc  :
*/
#include "iostream"
#include "vector"
#include "string"
using namespace std;

int main()
{
    int n ,q;
    cin>>n>>q;
    string s_ori ;
    cin>>s_ori;
    int a ,b;
    vector<vector<int>>op(q,vector<int>(2));
    for (int i = 0; i < q; ++i) {
        cin>>a>>b;
        a--;
        b--;
        op[i][0] = a;
        op[i][1] = b;
    }
    // cout<<"aaa"<<endl;
    // for (int i = 0; i < op.size(); ++i) {
    //     for (int j = 0; j < op[i].size(); ++j) {
    //         cout<<op[i][j]<< " ";
    //     }
    //     cout<<endl;
    // }
    for (int i = 0; i < q; ++i) {
        int length = op[i][1] - op[i][0]+1;
        int index1 = s_ori.size()-1;
        s_ori.resize(s_ori.size()+length);
        //
        int  index2 = s_ori.size()-1;
        while (index1>op[i][1])
        {
            s_ori[index2] = s_ori[index1];
            index1--;
            index2--;
        }
        while (index1>=op[i][0])
        {
            s_ori[index2] = s_ori[index1];
            index2--;
            s_ori[index2] = s_ori[index1];
            index2--;
            index1--;
        }
        // cout<<s_ori<<endl;

    }
    cout<<s_ori;
}

