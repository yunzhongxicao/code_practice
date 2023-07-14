/*
@File  :oppo_2.cpp
@Author:dfc
@Date  :2023/7/9  21:50
@Desc  :
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool is_valid(vector<int>& vec){
    for(int i:vec){
        if(i%2==1) return false;
    }
    return true;
}

int solution(string &str,int n,int k){
    int res=0;
    if(k%2==1) return 0;
    vector<int> record(26,0);
    for(int i=0;i<k;i++){
        record[str[i]-'a']++;
    }
    if(is_valid(record)) res++;
    for(int i=k;i<n;i++){
        record[str[i]-'a']++;
        record[str[i-k]-'a']--;
        if(is_valid(record)) res++;
    }
    return res;
}

int main() {
    int n,k;
    cin>>n>>k;
    string str;
    cin>>str;
    cout<<solution(str,n,k)<<endl;
    return 0;
}

