#include <bits/stdc++.h>
using namespace std;

void simplify(string& str){
    if(str.size()<3) return;
    int m=0;
    int h=0;
    int y=0;
    for(m=0;m<str.size();m++){
        if(str[m]!='m') continue;
        for(h=(m+1>h)? m+1:h;h<str.size();h++){
            if(str[h]!='h') continue;
            for(y=(h+1>y)? h+1:y;y<str.size();y++){
                if(str[y]!='y') continue;
                str[m]='-';
                str[h]='-';
                str[y]='-';
                break;
            }
            break;
        }
    }
    string new_str;
    for(int i=0;i<str.size();i++){
        if(str[i]!='-'){
            char c=str[i];
            new_str+=c;
        }
    }
    str=new_str;
}
void check(string& s,string& t){
    if(s==t){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return;
}
int main(){
    int n;
    cin>>n;
    vector<string> ss;
    vector<string> tt;
    string s;
    string t;
    for(int i=0;i<n;i++){
        cin>>s;
        ss.push_back(s);
        cin>>t;
        tt.push_back(t);
    }
    for(int i=0;i<n;i++){
        simplify(ss[i]);
        simplify(tt[i]);
        check(ss[i],tt[i]);
    }
    return 0;
}