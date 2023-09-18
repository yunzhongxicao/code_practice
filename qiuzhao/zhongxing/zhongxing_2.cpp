/*
@File  :zhongxing_2.cpp
@Author:dfc
@Date  :2023/9/8  19:47
@Desc  :
*/
#include "iostream"

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main(){
      int n;
      cin>>n;
      if(n>=9) cout<<""<<endl;
      unordered_map<int,vector<int>> left;
      unordered_map<int,vector<int>> right;
      for(int i=0;i<59;++i){
            int tmp=i,cnt=0;
            for(int j=0;j<4;++j){
                  if(tmp&1){
                        ++cnt;
                      }
                  tmp>>=1;
                }
            if(i<12) left[cnt].push_back(i);
            tmp=i,cnt=0;
            for(int j=0;j<6;++j){
                  if(tmp&1) ++cnt;
                  tmp>>=1;
                }
            right[cnt].push_back(i);
          }
      for(int i=0;i<=min(3,n);++i){
            int j=n-i;
            if(j>5) continue;
            auto lv=left[i];
            auto rv=right[j];
            for(int h:lv){
                  for(int m:rv){
                        if(m<10) cout<<h<<":"<<"0"<<m<<",";
                        else cout<<h<<":"<<m<<",";
                      }
                }
          }
}