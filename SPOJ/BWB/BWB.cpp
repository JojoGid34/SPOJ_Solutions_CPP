#include <cstdio>
#include <vector>

using namespace std;

#define MOD 1000000007
#define MAXN 10001
#define MAXK 101

// Menggunakan static agar masuk ke data segment (aman dari stack overflow)
int dp[MAXK][MAXN];

void precompute() {
    for (int k = 1; k < MAXK; k++) {
        dp[k][0] = 1; // Base case: string kosong dianggap 1 cara valid
        for (int n = 1; n < MAXN; n++) {
            if (n < k) {
                // Selama panjang n belum mencapai K, semua kombinasi (2^n) pasti valid
                dp[k][n] = (2LL * dp[k][n - 1]) % MOD;
            } 
            else if (n == k) {
                // Tepat saat n == K, ada 1 kombinasi yang melanggar (semuanya Hitam)
                // Jadi: 2^K - 1
                dp[k][n] = (2LL * dp[k][n - 1] - 1 + MOD) % MOD;
            } 
            else {
                // Logika DP Utama: 
                // Kita ambil semua cara valid kemarin, lalu kita coba tambah W atau B (kali 2).
                // Tapi, kita harus buang string yang "baru saja" membentuk K hitam berturut-turut.
                // String yang baru melanggar pasti berpola: [Valid string n-K-1] + [Putih] + [K Hitam]
                dp[k][n] = (2LL * dp[k][n - 1] - dp[k][n - k - 1] + MOD) % MOD;
            }
        }
    }
}

int main() {
    precompute();
    
    int t, n, k;
    if (scanf("%d", &t) == EOF) return 0;
    
    while (t--) {
        if (scanf("%d %d", &n, &k) == EOF) break;
        
        // Aturan: Manik pertama HARUS Putih.
        // Berarti kita tinggal mencari cara menyusun (N-1) manik sisanya
        // dengan batasan tidak ada K manik hitam berturut-turut.
        if (n == 0) printf("0\n");
        else printf("%d\n", dp[k][n - 1]);
    }
    
    return 0;
}
