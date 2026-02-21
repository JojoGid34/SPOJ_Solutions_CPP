#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;
const int MAX = 200005;

long long fact[MAX], invFact[MAX];

// Fungsi menghitung pangkat cepat (A^B % MOD)
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// Menghitung modular inverse menggunakan Fermat's Little Theorem
long long modInverse(long long n) {
    return power(n, MOD - 2);
}

// Fungsi precompute faktorial di awal
void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAX; i++) fact[i] = (fact[i - 1] * i) % MOD;
    invFact[MAX - 1] = modInverse(fact[MAX - 1]);
    for (int i = MAX - 2; i >= 0; i--) invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
}

// Fungsi kombinasi nCr
long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
}

void solve(int t) {
    int N, M, K;
    cin >> N >> M >> K;

    // Jika diminta 0 warna, probabilitasnya pasti 1
    if (K <= 0) {
        cout << "Case " << t << ": 1" << endl;
        return;
    }
    // Jika K lebih besar dari pilihan warna atau jumlah lapisan, mustahil
    if (K > N || K > M) {
        cout << "Case " << t << ": 0" << endl;
        return;
    }

    long long totalWays = 0;

    // Implementasi Rumus Ajaib: Sum_{j=1}^N j^M * C(N, j) * InnerSum(j)
    for (int j = 1; j <= N; j++) {
        long long term = (power(j, M) * nCr(N, j)) % MOD;
        long long innerSum = 0;

        if (j == N) {
            innerSum = 1;
        } else if (j < K) {
            // InnerSum = (-1)^(K-j) * C(N-j-1, K-j-1)
            innerSum = nCr(N - j - 1, K - j - 1);
            if ((K - j) % 2 == 1) {
                innerSum = (MOD - innerSum) % MOD;
            }
        } else {
            // j >= K dan j < N, InnerSum nya 0
            innerSum = 0;
        }

        if (innerSum != 0) {
            totalWays = (totalWays + (term * innerSum)) % MOD;
        }
    }

    // Probabilitas = TotalWays / N^M
    long long totalPossible = power(N, M);
    long long result = (totalWays * modInverse(totalPossible)) % MOD;

    cout << "Case " << t << ": " << result << endl;
}

int main() {
    // Mempercepat input-output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(i);
    }

    return 0;
}
