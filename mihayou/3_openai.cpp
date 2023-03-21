/*
@File  :3_openai.cpp
@Author:dfc
@Date  :2023/3/19  21:13
@Desc  :
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// ���������������Լ��
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

// �������Լ��
int calculateGCD(const vector<int>& nums) {
    int res = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        res = gcd(res, nums[i]);
    }
    return res;
}

// ���� n ����������
vector<int> getFactors(int n) {
    vector<int> factors;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i != n / i) {
                factors.push_back(n / i);
            }
        }
    }
    return factors;
}

// ��������� C(n, k)
long long C(int n, int k) {
    if (k > n) return 0;
    long long res = 1;
    for (int i = 1; i <= k; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

int countSubsets(const vector<int>& nums) {
    int n = nums.size();
    int gcd_val = calculateGCD(nums);
    vector<int> quotients(n);
    unordered_map<int, int> factors_count;
    for (int i = 0; i < n; ++i) {
        quotients[i] = nums[i] / gcd_val;
        vector<int> factors = getFactors(quotients[i]);
        for (int factor : factors) {
            ++factors_count[factor];
        }
    }
    int res = 0;
    for (const auto& [factor, count] : factors_count) {
        for (int k = 2; k <= count; ++k) {
            res += C(count, k);
        }
    }
    return res;
}

int main() {
    vector<int> nums = {1,2,3,4,5};
    cout << "�����������Ӽ�����Ϊ: " << countSubsets(nums) << endl;
    return 0;
}


