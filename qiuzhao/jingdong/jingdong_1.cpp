/*
@File  :jingdong_1.cpp
@Author:dfc
@Date  :2023/8/19  9:59
@Desc  :
*/
#include "iostream"
#include "vector"
#include "string"

using namespace std;

int check(int middle, int left,int  right)
{
    if(middle==0)
        return 0; // 没人夹持
    if(middle==2 and left==1 and right==1)
        return 2; // 2被夹持
    if(middle==1 and left==2 and right ==2)
        return 1;
    return 0;

}

void solution(vector<vector<int>> &chess)
{
    bool flag1=false, flag2 = false;

    int tmp;
    tmp = check(chess[0][1],chess[0][0],chess[0][2]);
    if(tmp==1)
        flag1 =true;
    else if(tmp==2)
        flag2 = true;

    tmp = check(chess[1][1],chess[1][0],chess[1][2]);
    if(tmp==1)
        flag1 =true;
    else if(tmp==2)
        flag2 = true;

    tmp = check(chess[1][1],chess[0][1],chess[2][1]);
    if(tmp==1)
        flag1 =true;
    else if(tmp==2)
        flag2 = true;

    tmp = check(chess[2][1],chess[2][0],chess[2][2]);
    if(tmp==1)
        flag1 =true;
    else if(tmp==2)
        flag2 = true;

    tmp = check(chess[1][0],chess[0][0],chess[2][0]);
    if(tmp==1)
        flag1 =true;
    else if(tmp==2)
        flag2 = true;

    tmp = check(chess[1][2],chess[0][2],chess[2][2]);
    if(tmp==1)
        flag1 =true;
    else if(tmp==2)
        flag2 = true;

    if ((flag1 and flag2) or (!flag1 and !flag2))
    {
        cout<<"draw"<<endl;
        return;
    }
    if (flag1 and !flag2)
    {
        cout<<"kou"<<endl;
        return;
    }
    if(!flag1 and flag2)
    {
        cout<<"yukari"<<endl;
        return;
    }
}

int main()
{
    int t;
    cin>>t;
    for (int i = 0; i < t; ++i) {
        vector<vector<int>> chess(3,vector<int>(3,0));
        string s_tmp;
        cin>>s_tmp;
        for (int j = 0; j <3 ; ++j) {
            if (s_tmp[j]=='.')
                chess[0][j] = 0;
            else if(s_tmp[j]=='o')
                chess[0][j] = 1;
            else if(s_tmp[j]=='*')
                chess[0][j]=2;
        }

        cin>>s_tmp;
        for (int j = 0; j <3 ; ++j) {
            if (s_tmp[j]=='.')
                chess[1][j] = 0;
            else if(s_tmp[j]=='o')
                chess[1][j] = 1;
            else if(s_tmp[j]=='*')
                chess[1][j]=2;
        }

        cin>>s_tmp;
        for (int j = 0; j <3 ; ++j) {
            if (s_tmp[j]=='.')
                chess[2][j] = 0;
            else if(s_tmp[j]=='o')
                chess[2][j] = 1;
            else if(s_tmp[j]=='*')
                chess[2][j]=2;
        }

        solution(chess);
    }
}
