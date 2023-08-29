/*
@File  :kedaxunfei_2.cpp
@Author:dfc
@Date  :2023/7/22  20:19
@Desc  :
*/
#include <iostream>
#include <vector>

using namespace std;

bool check(vector<int>& a,vector<int>& b,int l,int r){
    int j=r;
    for(int i=l;i<=r;i++){
        if(a[i]!=b[j]) return false;
        else j--;
    }
    return true;
}

int solution(vector<int>& a,vector<int>& b,int n){
    int result=0;
    int l=0;
    int r=n-1;
    int l_max=l;
    int r_min=r;
    while(a[l_max]==b[l_max]&&l_max<=r){
        l_max++;
    }
    if(l_max<=r){
        while(a[r_min]==b[r_min]){
            r_min--;
        }
        while(check(a,b,l_max,r_min)){
            result++;
            l_max--;
            r_min++;
            if(l_max<l||r_min>r) break;
        }
    }
    else{//两数组一致 似乎只能暴力
        for(int i=0;i<=r;i++){
            for(int j=i;j<=r;j++){
                if(check(a,b,i,j)) result++;
            }
        }
    }
    return result;
}


int main() {
    int n;
    cin>>n;
    vector<int> a(n,0);
    vector<int> b(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int res= solution(a,b,n);
    cout<<res;
    return 0;
}
