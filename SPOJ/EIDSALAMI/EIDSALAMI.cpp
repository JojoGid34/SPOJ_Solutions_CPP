#include <iostream>

using namespace std;

void solve(int caseNum) {
    long long M;
    if (!(cin >> M)) return;

    // A: Total cara membagi M jadi 3 angka positif (x+y+z=M, x,y,z >= 1)
    // Pakai long long karena M-1 * M-2 bisa sampai 10^12
    long long A = (M - 1) * (M - 2) / 2;

    // S: Banyaknya solusi untuk 2x + z = M (kasus ada yang sama)
    long long S = (M - 1) / 2;

    // C: Apakah M bisa dibagi 3 rata? (kasus x=y=z)
    long long C = (M % 3 == 0) ? 1 : 0;

    // Rumus: (Total - cara_ada_yang_sama) / 6 permutasi
    // Kita kurangi kasus 2 yang sama (3 pasang) dan 3 yang sama
    long long ans = (A - 3 * (S - C) - C) / 6;

    cout << "Case " << caseNum << ": " << ans << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(i);
    }
    return 0;
}
