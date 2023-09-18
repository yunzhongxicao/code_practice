/*
@File  :baidu_2.cpp
@Author:dfc
@Date  :2023/9/12  19:50
@Desc  :
*/

#include <iostream>
#include <vector>
using namespace std;

void solution(vector<int> &zan , vector<int> &cai)
{
    long long result1 = 0;
    long long result2 = 0;
    for (int i = 0; i < zan .size(); ++i) {  // 两种情况 要么都是赞大于踩  要么踩大于赞 不能混在一起 会抵消热度
        if (zan[i] > cai[i]) result1  += zan[i] - cai[i];
        else result2 += cai[i] - zan[i];
    }
    cout<<max(result1,result2);
}

int main(){
    int n;
    cin>>n;
    vector<int> zan(n,0);
    vector<int> cai(n,0);
    for(int i=0;i<n;i++){
        cin>>zan[i];
    }
    for(int i=0;i<n;i++){
        cin>>cai[i];
    }
    solution(zan, cai);
    return 0;
}
