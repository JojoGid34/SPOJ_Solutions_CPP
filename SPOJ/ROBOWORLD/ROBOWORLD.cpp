#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

// Fungsi mencari FPB (GCD)
ull gcd(ull a, ull b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// Fungsi paling penting: Mengubah string "7.4" jadi angka 74000
ull parseToLong(string s) {
    size_t dot = s.find('.');
    if (dot == string::npos) {
        // Kalau nggak ada titik, tinggal kali 10.000
        return stoull(s) * 10000;
    }
    
    ull depan = stoull(s.substr(0, dot));
    string belakangS = s.substr(dot + 1);
    
    // Pastikan bagian belakang selalu 4 digit (pad dengan nol)
    while (belakangS.length() < 4) belakangS += '0';
    if (belakangS.length() > 4) belakangS = belakangS.substr(0, 4);
    
    ull belakang = stoull(belakangS);
    return depan * 10000 + belakang;
}

void solve() {
    int n;
    cin >> n;
    
    ull sumX = 0, sumY = 0;
    for (int i = 0; i < n; i++) {
        string xStr, yStr;
        cin >> xStr >> yStr;
        sumX += parseToLong(xStr);
        sumY += parseToLong(yStr);
    }
    
    // Sesuai logika: a * sumX = b * sumY
    // Maka a/b = sumY / sumX
    // Kita sederhanakan pecahan sumY / sumX
    ull common = gcd(sumX, sumY);
    
    ull a = sumY / common;
    ull b = sumX / common;
    
    cout << "f(x) = " << a << "x, g(x) = " << b << "x" << endl;
}

int main() {
    // Biar input-output cepet
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
