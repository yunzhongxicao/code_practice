/*
@File  :lingxi_1.cpp
@Author:dfc
@Date  :2023/8/27  18:51
@Desc  :
*/
#include <iostream>
#include <vector>
#include <cmath>
#include "unordered_set"
#include "string"
#include "unordered_map"
using namespace std;

unordered_set<int> primes;

void find_primes(int limit) {
    vector<bool> is_prime(limit + 1, true);
    // std::vector<int> primes;
    //
    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 2; i <= sqrt(limit); ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= limit; ++i) {
        if (is_prime[i]) {
            primes.insert(i);
        }
    }
    // return primes;
}

void solution(string s)
{
    vector<int> fre(26,0);
    for (int i = 0; i < s.size(); ++i) {
        fre[s[i]-'a']++;
    }
    int max_count = 0;
    for (int i = 0; i < 26; ++i) {
        if (fre[i]>=max_count)
            max_count = fre[i];
    }
    if (primes.find(max_count) != primes.end())
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main()
{
    int n;
    cin>>n;
    find_primes(10000);
    for (int i = 0; i < n; ++i) {
        string s;
        cin>>s;
        solution(s);
    }
}

