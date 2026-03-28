#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve(int caseNum) {
    int N;
    cin >> N;
    
    vector<int> A(N);
    long long totalRobots = 0;
    int oddCount = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        totalRobots += A[i];
        if (A[i] % 2 != 0) {
            oddCount++;
        }
    }
    
    bool possible = false;
    
    // Skenario 1: Jumlah Baris Genap (R = 2, 4, 6...)
    // Syarat: Semua jumlah robot warna harus genap (oddCount == 0)
    if (oddCount == 0) {
        possible = true;
    } 
    // Skenario 2: Jumlah Baris Ganjil (R = 3, 5, 7...)
    else {
        // Kita cari pembagi ganjil R dari totalRobots (R >= 3)
        for (long long R = 3; R <= totalRobots; R += 2) {
            if (totalRobots % R == 0) {
                long long C = totalRobots / R; // Kapasitas per baris
                
                // Syarat baris tengah:
                // 1. Kapasitas C harus cukup buat nampung minimal 1 robot tiap warna ganjil
                // 2. Sisa slot (C - oddCount) harus bisa diisi sepasang-sepasang (genap)
                if (C >= oddCount && (C - oddCount) % 2 == 0) {
                    possible = true;
                    break;
                }
            }
        }
    }
    
    cout << "Caso #" << caseNum << ": ";
    if (possible) {
        cout << "Challenge Accepted!" << endl;
    } else {
        cout << "Run for your life!" << endl;
    }
}

int main() {
    int T;
    if (!(cin >> T)) return 0;
    for (int i = 1; i <= T; i++) {
        solve(i);
    }
    return 0;
}
