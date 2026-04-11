#include <iostream>
#include <cstdio>
using namespace std;

#define MOD 1000000007

int DP[101][4951], ans;

int main() {
    int t, no = 1;

    DP[1][0] = 1;
    for(int i = 2; i <= 100; i++) {
        DP[i][0] = 1;
        for(int j = 1; j <= i*(i-1)/2; j++) {
            if(j < i) 
                DP[i][j] = (DP[i][j-1] + DP[i-1][j]) % MOD;
            else 
                DP[i][j] = ((DP[i][j-1] + DP[i-1][j] - DP[i-1][j-i]) % MOD + MOD) % MOD;
        }
    }

    cin >> t;
    while(t--) {
        int i, j;
        cin >> i >> j;

        if (j > 4950) ans = 0;
        else ans = DP[i][j];

        printf("Case %d: %d\n", no++, ans);
    }

    return 0;
}
