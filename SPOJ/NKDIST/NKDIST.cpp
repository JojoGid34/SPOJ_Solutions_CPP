#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// __int128 wajib karena hex 30 digit itu raksasa
typedef __int128_t int128;

// Fungsi bantu untuk baca/tulis __int128 ke string desimal
string toDecStr(int128 n) {
    if (n == 0) return "0";
    string s = "";
    while (n > 0) {
        s += (char)((n % 10) + '0');
        n /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

// Ubah Hex ke __int128
int128 hexTo128(string s) {
    int128 res = 0;
    for (char c : s) {
        res *= 16;
        if (c >= '0' && c <= '9') res += (c - '0');
        else res += (c - 'A' + 10);
    }
    return res;
}

// Ubah __int128 ke Hex
string toHex(int128 n) {
    if (n == 0) return "0";
    string s = "";
    string h = "0123456789ABCDEF";
    while (n > 0) {
        s += h[(int)(n % 16)];
        n /= 16;
    }
    reverse(s.begin(), s.end());
    return s;
}

// Menghitung jumlah digit dalam D sebelum angka X muncul
int128 getPos(int128 X) {
    if (X <= 0) return 0;
    string sX = toHex(X);
    int L = sX.length();
    int128 total = 0;
    int128 p16 = 1;

    for (int i = 1; i < L; ++i) {
        int128 count = (i == 1) ? 15 : (p16 * 15);
        total += count * i;
        if (i == 1) p16 = 16; else p16 *= 16;
    }
    int128 startVal = (L == 1) ? 1 : (p16);
    total += (X - startVal) * (int128)L;
    return total;
}

// Verifikasi apakah S benar-benar terbentuk dari barisan X, X+1, ...
bool isValid(int128 X, int k, const string& S) {
    if (X <= 0) return false;
    string temp = "";
    int128 cur = X;
    while ((int)temp.length() < (int)S.length() + k) {
        string h = toHex(cur++);
        temp += h;
        if (temp.length() > 500) break; 
    }
    if ((int)temp.length() < k + (int)S.length()) return false;
    return temp.substr(k, S.length()) == S;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string S;
    if (!(cin >> S)) return 0;

    set<int128> results;
    int n = S.length();

    // Strategi: Cek semua kemungkinan panjang angka L (1-31)
    for (int L = 1; L <= 31; ++L) {
        for (int k = 0; k < L; ++k) {
            // Kita coba tebak angka X berdasarkan potongan S
            // Ambil bagian S yang seharusnya ada di dalam angka X
            string sub = S.substr(0, min(n, L - k));
            
            // Buat angka X terkecil yang mengandung sub di posisi k
            string valStr = "";
            for(int i=0; i<k; ++i) valStr += (i == 0 ? '1' : '0');
            valStr += sub;
            while((int)valStr.length() < L) valStr += '0';
            
            int128 X = hexTo128(valStr);
            
            // Cek X dan sekitarnya (antisipasi carry/pindahan nilai)
            for (int128 cand = X; cand <= X + 2; ++cand) {
                if (isValid(cand, k, S)) results.insert(getPos(cand) + k);
            }
            if (X > 1) {
                if (isValid(X - 1, k, S)) results.insert(getPos(X - 1) + k);
            }
        }
    }

    // Ambil dua posisi terkecil dan hitung jaraknya
    if (results.size() >= 2) {
        auto it = results.begin();
        int128 p1 = *it; it++;
        int128 p2 = *it;
        cout << toDecStr(p2 - (p1 + n)) << endl;
    }

    return 0;
}
