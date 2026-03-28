#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, q, m;
    if (!(cin >> n >> q >> m)) return;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // dp[hari][jumlah_uang] = apakah uang sejumlah itu bisa dicapai?
    // n <= 50, m <= 1000
    vector<vector<bool> > dp(n + 1, vector<bool>(m + 1, false));

    // Kondisi awal (Hari 0): Uang awal kita adalah q
    dp[0][q] = true;

    // Iterasi setiap hari
    for (int i = 1; i <= n; i++) {
        int amount = a[i - 1]; // Angka hari ini
        bool possible_today = false;

        for (int j = 0; j <= m; j++) {
            // Kalau uang 'j' bisa dicapai kemarin (hari i-1)
            if (dp[i - 1][j]) {
                // Pilihan 1: Tambah uang
                if (j + amount <= m) {
                    dp[i][j + amount] = true;
                    possible_today = true;
                }
                // Pilihan 2: Kurangi uang
                if (j - amount >= 0) {
                    dp[i][j - amount] = true;
                    possible_today = true;
                }
            }
        }
        
        if (!possible_today) {
		    cout << -1 << endl;
		    return;
		}
    }

    // Cari uang terbesar di hari terakhir (n)
    int max_money = -1;
    for (int j = m; j >= 0; j--) {
        if (dp[n][j]) {
            max_money = j;
            break;
        }
    }

    cout << max_money << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
