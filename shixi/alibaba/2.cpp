/*
@File  :2.cpp
@Author:dfc
@Date  :2023/3/26  14:50
@Desc  :
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
        constexpr int MAX_NUM = 200000;
        vector<bool> isPrime(MAX_NUM, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i < MAX_NUM; i++) {
                if (isPrime[i]) {
                        for (int j = i + i; j < MAX_NUM; j += i) {
                                isPrime[j] = false;
                            }
                    }
            }

        int n;
        cin >> n;
        if (n == 1) {
                printf("1");
                return 0;
            }

        vector<int> next(n);
        for (int i = 0; i < n; i++) {
                next[i] = (i + 1) % n;
            }

        int count = 2;
        int prev = 0;
        int curr = 1;
        while (next[curr] != curr) {
                curr = next[curr];
                if (isPrime[count]) {
                        next[prev] = curr;
                    } else {
                        prev = next[prev];
                    }
                count++;
            }
        printf("%d", curr + 1);
        return 0;
}

