#include <bits/stdc++.h>
using namespace std;

int main() {
          int n;
          cin >> n;
          vector<long long> arr(n, 0);
          for (int i = 0; i < n; i++) {
                    int a;
                    cin >> a;
                    if (i == 0)
                          arr[i] = a;
                    else
                          arr[i] = arr[i - 1] + a;
              }

          if (arr.back() % 2 != 0) {
                    cout << 0 << endl;
                    return 0;
              }

          unordered_map<long long, int> m;
          long long half = arr.back() / 2;
          int ans = 0;
          for (int i = 0; i < n; i++) {
                    ans += m[arr[i] - half];
                    m[arr[i]]++;
              }
          cout << ans << endl;
          return 0;
}