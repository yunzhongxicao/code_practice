#include <iostream>
#include <string>
using namespace std;

// 构造仅由'r'、'e'、'd'三种字符组成的字符串，其中回文子串数量为 t（每个单独的字母也算一个回文串）
string build(int t) {
    if (t <= 3) {
        return string(3*t, 'r') + string(3*t, 'e') + string(3*t, 'd');
    } else {
        string res;
        for (int i = 0; i < t/3; i++) {
            res += "redred";
        }
        int m = t % 3;
        if (m == 1) {
            res += "re";
        } else if (m == 2) {
            res += "re";
        } else {
            res += "redred";
        }
        return res;
    }
}

int main() {
    int t;
    cin >> t;
    cout << build(t) << endl;
    return 0;
}
