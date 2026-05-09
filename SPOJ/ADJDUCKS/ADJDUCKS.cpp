#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

// Gunakan nilai yang sangat besar untuk inisialisasi INF
const ll INF = 2e18; 

int main() {
    // Optimasi I/O biar kenceng
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<ll> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    // Langkah 1: Sorting bebek berdasarkan nadanya
    sort(p.begin(), p.end());

    // Langkah 2: Buat array DP (ukuran n + 1)
    vector<ll> dp(n + 1, INF);

    // Base Case
    dp[0] = 0; // 0 bebek, 0 biaya
    // dp[1] tetap INF karena 1 bebek nggak boleh sendirian

    for (int i = 2; i <= n; i++) {
        // Pilihan 1: Bebek ke-i masuk grup isi 2 (pasangan)
        if (dp[i - 2] != INF) {
            dp[i] = min(dp[i], dp[i - 2] + (p[i - 1] - p[i - 2]));
        }

        // Pilihan 2: Bebek ke-i masuk grup isi 3 (trio)
        if (i >= 3 && dp[i - 3] != INF) {
            dp[i] = min(dp[i], dp[i - 3] + (p[i - 1] - p[i - 3]));
        }
    }

    // Langkah 3: Output jawaban akhir
    cout << dp[n] << endl;

    return 0;
}
