#include <cstdio>
#include <cstring>

int t, N, Q, M;
int a[51];
bool dp[2][1001];

int main() {
    t = getNum<int>();
    while (t--) {
        N = getNum<int>();
        Q = getNum<int>();
        M = getNum<int>();

        for (int i = 0; i < N; i++)
            a[i] = getNum<int>();

        memset(dp, 0, sizeof(dp));
        dp[0][Q] = 1;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (dp[i % 2][j]) {
                    if (j + a[i] <= M)
                        dp[(i + 1) % 2][j + a[i]] = 1;
                    if (j - a[i] >= 0)
                        dp[(i + 1) % 2][j - a[i]] = 1;
                }
                dp[i % 2][j] = 0;
            }
        }

        int maxV = 1;
        for (int i = M; i >= 0; i--) {
            if (dp[N % 2][i]) {
                maxV = i;
                break;
            }
        }

        printf("%d\n", maxV);
    }
    return 0;
}
