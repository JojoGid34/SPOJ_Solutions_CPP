#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    //Supaya ga TLE dan I/O nya ngebut
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        ll N;
        cin >> N;

        //C(n) = 4n + 1
        //F(n) = n(2n-1) + 1 = 2n^2 - n + 1
        ll ans = 2*N*N - N + 1;
        cout << ans << '\n';
    }

    return 0;
}
