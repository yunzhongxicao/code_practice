/*
@File  :xiaohongshu_2.cpp
@Author:dfc
@Date  :2023/7/23  20:18
@Desc  :
 */
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> status(n, 0);
    int l,r;
    for(int i=0;i<m;i++){//按位置记录精华帖
        cin>>l>>r;
        status[l]+=1;
        status[r]-=1;
    }
    int res=0,cur_res=0;
    int left,right;
    int left_status=0,right_status=0;
    for(right=0;right<k;right++){
        right_status+=status[right];
        cur_res+=right_status;
    }//此时right=k，左闭右开区间
    if(cur_res>res) res=cur_res;
    for(left=0;left<n-k;left++){
        left_status+=status[left];
        right_status+=status[right];
        cur_res-=left_status;
        cur_res+=right_status;
        if(cur_res>res) res=cur_res;
        right++;
    }
    cout<<res;
    return 0;
}

