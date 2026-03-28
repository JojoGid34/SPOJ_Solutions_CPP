#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    // Biar input/output ngebut, standar kompetisi
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;

    // Pakai konstanta PI yang presisi
    const double PI = acos(-1.0);

    while (T--) {
        double S, L, R;
        if (!(cin >> S >> L >> R)) break;

        // 1. Bagian atas & bawah: 2 * S * R
        // 2. Bagian samping (1/2 tabung): 1/2 * PI * R^2 * L
        // 3. Bagian pojok (total jadi 1 bola utuh): 4/3 * PI * R^3
        double volume = (2.0 * S * R) 
                      + (0.5 * PI * R * R * L) 
                      + ((4.0 / 3.0) * PI * R * R * R);

        // Output dengan presisi sesuai permintaan soal
        cout << fixed << setprecision(3) << volume << "\n";
    }

    return 0;
}
