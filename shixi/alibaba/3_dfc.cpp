/*
@File  :3_dfc.cpp
@Author:dfc
@Date  :2023/3/26  14:31
@Desc  :
*/
#include <iostream>
#include <vector>
#include <map>
#include "queue"
using namespace std;

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int max_prime_factor_smaller_than_n(int n) {
    for (int i = n; i >= 2; i--) {
        if (is_prime(i) && n % i == 0) {
            return i;
        }
    }
    return -1; // 没有找到素因子
}

class mycomparison
{
public:
    bool operator()(const pair<int,int >& lhs, const pair<int,int > & rhs ) //通过在 cmp 类（结构体）重载的 () 运算符中自定义排序规则
    {
        return lhs.second<rhs.second;
    }
};

int main() {
    // int n = 5;
    // cout<<max_prime_factor_smaller_than_n(5);
    int n,k;
    cin>>n>>k;
    vector<int>nums(n);
    for (int i = 0; i < n; ++i) {
        cin>>nums[i];
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,mycomparison >my_que;
    int result = 0;
    for (int i = 0; i <n ; ++i) {
        int temp = max_prime_factor_smaller_than_n(nums[i]); // 最大质数因子
        int temp_cost =nums[i]- nums[i] / temp;
        my_que.push(pair<int,int>{nums[i],temp_cost});
        result += nums[i];
    }

    for (int i = 0; i < k; ++i) {
        pair<int,int> temp = my_que.top();
        my_que.pop();
        result -=temp.second;
        int yinzi = temp.first / (temp.first-temp.second);
        int update_num = temp.first / yinzi;
        if (update_num>1)
        {
            int update_yinzi = max_prime_factor_smaller_than_n(update_num);
            int update_cost = update_num - update_num/update_yinzi;
            my_que.push(pair<int,int>{update_num,update_cost});
        }
    }
    cout<<result;
    return 0;
}


