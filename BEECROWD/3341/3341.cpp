#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <algorithm>

using namespace std;

typedef complex<double> cd;
const double PI = acos(-1);

// Fungsi FFT buat ngubah koefisien jadi titik (dan sebaliknya)
void fft(vector<cd>& a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert) {
        for (cd & x : a) x /= n;
    }
}

void solve() {
    int d1, d2, q;
    if (scanf("%d %d %d", &d1, &d2, &q) != 3) return;

    // Cari nilai max buat nentuin ukuran array
    int max_val = 100000;
    int n = 1;
    while (n <= 2 * max_val) n <<= 1;

    vector<cd> fa(n), fb(n);
    for (int i = 0; i < d1; i++) {
        int val; scanf("%d", &val);
        fa[val] += 1;
    }
    for (int i = 0; i < d2; i++) {
        int val; scanf("%d", &val);
        fb[val] += 1;
    }

    // Proses Konvolusi (Perkalian Polinomial)
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++) fa[i] *= fb[i];
    fft(fa, true);

    // Hasilnya kita simpen di array biar query tinggal panggil O(1)
    vector<long long> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = round(fa[i].real());
    }

    while (q--) {
        int v;
        scanf("%d", &v);
        if (v >= n || v < 0) printf("0\n");
        else printf("%lld\n", result[v]);
    }
}

int main() {
    solve();
    return 0;
}
