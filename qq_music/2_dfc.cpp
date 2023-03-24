/*
@File  :2_dfc.cpp
@Author:dfc
@Date  :2023/3/23  19:23
@Desc  :
*/
#include <bits/stdc++.h>
using namespace std;

int res=INT_MAX;

int getValue(string& s,int startIndex,int endIndex){
    vector<int> num(26,0);
    int typeNum=0;
    for(int i=startIndex;i<=endIndex;i++){
        num[s[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        if(num[i]!=0) typeNum++;
    }
    return (endIndex-startIndex+1)*typeNum;
};

void backtracking(string& s,int startIndex,int leftCutTime,int currentValue){
    if(leftCutTime==0){//对最后一段字符串进行计算权值
        int lastValue=getValue(s,startIndex,s.size()-1);
        if(lastValue<res){
            res=max(currentValue,lastValue);
        }
        return;
    }
    vector<int> num(26,0);
    int length=0;
    int type=0;
    for(int i=startIndex;i<s.size()-leftCutTime;i++){
        if(num[s[i]-'a']==0) type++;
        num[s[i]-'a']++;
        length++;
        int thisValue=length*type;
        if(thisValue<res){
            backtracking(s,i+1,leftCutTime-1,max(currentValue,thisValue));
        }
        else break;
    }
}

int getMaxValue(string str, int k) {
    res=INT_MAX;
    backtracking(str,0,k-1,1);
    return res;
}


int main() {
    string s = "ababbbb";
    int k = 2;
    cout << getMaxValue(s, k) << endl;
    return 0;
}



