#include <iostream>
#include <vector>

using namespace std;

const int MOD = 5000011;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> dp(n + 1);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        // Pilihan 1: Ujungnya Perempuan
        dp[i] = dp[i - 1];

        // Pilihan 2: Ujungnya Laki-laki
        if (i - k - 1 >= 0) {
            dp[i] = (dp[i] + dp[i - k - 1]) % MOD;
        } else {
            // Jika i <= K, cuma bisa ada 1 boy di ujung dan sisanya girl
            dp[i] = (dp[i] + 1) % MOD;
        }
    }

    cout << dp[n] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    cin >> c;
    while (c--) {
        solve();
    }
    return 0;
}
