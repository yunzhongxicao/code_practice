/*
@File  :xyz_1.cpp
@Author:dfc
@Date  :2023/9/3  22:26
@Desc  :
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;


// 请按你的实际需求修改参数和返回值类型
vector<int> solution(const vector<int> &arr1, const vector<int> arr2)
{
    // 在这?写代码
    unordered_set<int> record;
    for(int num:arr2){
        record.insert(num);
    }
    vector<int> last;
    unordered_map<int,int> umap;
    for(int num:arr1){
        if(record.find(num)!=record.end()){
            umap[num]++;
        }
        else{
            last.push_back(num);
        }
    }
    sort(last.begin(),last.end());
    vector<int> res;
    for(int num:arr2){
        for(int i=0;i<umap[num];i++){
            res.push_back(num);
        }
    }
    for(int num:last){
        res.push_back(num);
    }
    return res;
}

