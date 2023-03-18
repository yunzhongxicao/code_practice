#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int count_players_with_mana(int n, int delay, int forget) {
    std::vector<int> players(n + 1, 0);
    players[1] = 1;
    int mana_sum = 1;

    for (int i = 2; i <= n; ++i) {
        if (i - delay - 1 >= 1) {
            players[i] = (players[i - 1] - players[i - delay - 1] + MOD) % MOD;
        } else {
            players[i] = players[i - 1];
        }
        if (i - forget - delay >= 1) {
            players[i] = (players[i] - players[i - forget - delay] + MOD) % MOD;
        }
        mana_sum = (mana_sum + players[i]) % MOD;
    }

    return mana_sum;
}

int main() {
    int n1 = 6, delay1 = 2, forget1 = 4;
    int n2 = 4, delay2 = 1, forget2 = 3;
    std::cout << "Result for n=6, delay=2, forget=4: " << count_players_with_mana(n1, delay1, forget1) << std::endl;
    std::cout << "Result for n=4, delay=1, forget=3: " << count_players_with_mana(n2, delay2, forget2) << std::endl;
    return 0;
}
