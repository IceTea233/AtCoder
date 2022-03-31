#include<bits/stdc++.h>
#define int long long
#define all(x) begin(x), end(x)
#define SZ(x) ((int)(x).size())
#define EB emplace_back
#define PB push_back
#define PP pop_back
#define MP make_pair
#define F first
#define S second
#define de(x) if(x && x == MODE)
#define MODE 0

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 4e2 + 7;
const int MOD = 998244353;

int fac[maxn] = {};
bool adj[maxn][maxn] = {};
int dp[maxn][maxn] = {};

int pwr(int x, int k) {
    int ret = 1;
    while (k) {
        if (k & 1)
            ret = ret * x % MOD;
        x = x * x % MOD;
        k >>= 1;
    }
    return ret;
}

int inv(int x) {
    return pwr(x, MOD-2);
}

int C(int a, int b) {
    return fac[a] * inv(fac[b]) % MOD * inv(fac[a-b]) % MOD;
}

void prepare() {
    fac[0] = 1;
    for (int i=1; i<maxn; i++)
        fac[i] = fac[i-1] * i % MOD;
}



int32_t main() {
    cin.tie(0);
    int i,j;
    int N,M;

    cin >> N >> M;
    prepare();
    for (int i=1; i<=M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = true;
        adj[b][a] = true;
    }

    for (int i=2; i<=N*2; i += 2) {
        for (int j=1; j+i-1 <= N*2; j++) {
            if (i == 2) {
                if (adj[j][j+1])
                    dp[j][j+1] = 1;
            } else {
                for (int k=j+1; k <= j+i-1; k++) {
                    if (adj[j][k]) {
                        if (k == j+i-1) {
                            de(1) printf("Case 1\n");
                            de(1) printf("[%lld, %lld]\n", j, k);
                            de(1) printf("[%lld, %lld] add %lld\n", j, j+i-1, dp[j+1][j+i-2]);
                            dp[j][j+i-1] += dp[j+1][j+i-2];
                            dp[j][j+i-1] %= MOD;
                            // de(1) printf(">>> %lld\n", dp[j][j+i-1]);
                        }
                        else if (k == j+1) {
                            de(1) printf("Case 2\n");
                            de(1) printf("[%lld, %lld], (%lld, %lld)\n", j, k, k+1, j+i-1);
                            de(1) printf("[%lld, %lld] add %lld\n", j, j+i-1, dp[k+1][j+i-1] * C(i / 2, 1));
                            de(1) printf("%lld * %lld C(%lld, %lld)\n", dp[k+1][j+i-1], C(i / 2, 1), i/2, 1);
                            dp[j][j+i-1] += dp[k+1][j+i-1] * C(i / 2, 1) % MOD;
                            dp[j][j+i-1] %= MOD;
                        }
                        else {
                            de(1) printf("Case 3\n");
                            de(1) printf("[%lld, %lld], (%lld, %lld)\n", j, k, k+1, j+i-1);
                            de(1) printf("[%lld, %lld] add %lld\n", j, j+i-1, dp[j+1][k-1] * dp[k][j+i-1] % MOD * C(i / 2, (k - j + 1) / 2) % MOD);
                            de(1) printf("%lld * %lld C(%lld, %lld)\n", dp[j+1][k-1] * dp[k+1][j+i-1], C(i / 2, 1), i/2, 1);
                            dp[j][j+i-1] += dp[j+1][k-1] * dp[k+1][j+i-1] % MOD * C(i / 2, (k - j + 1) / 2) % MOD;
                            dp[j][j+i-1] %= MOD;
                        }
                    }
                }
            }
        }
    }

    de(1) {
        for (int i=1; i<=N*2; i++) {
            for (int j=i; j<=N*2; j++) {
                printf("dp[%lld][%lld] = %lld\n", i, j, dp[i][j]);
            }
        }
    }

    int ans = dp[1][N*2];
    printf("%lld\n", ans);

    return 0;
}

//
//          ___ ___  __________  __________
//         /////\  \/\   ______\/\\\\\\\\\\\  Code by ~Ice Tea~ of
//        //// \ \  \ \  \_____/\ \\\\_____/      New Empire of CHSH ...
//       ////   \ \  \ \  \      \ \\\\\\\\\\\
//      ////__   \ \  \ \  \      \ \\\\_____/
//     ///////\   \ \  \ \  \______\ \\\\_______   ________
//    ////____/    \ \__\ \___   ___\ \\\\\\\\\\\ _\  ___  \_
//   /__/           \/__/\/__/\  \__/\ \\\\_____//\  .\_/\_  \
//                           \ \  \   \ \\\\\\\\\\\\  \_\/_\  \
// ... with the AC Power of   \ \  \   \ \\\\_____/ \   _____  \
//   The Great Tsundere Doggy. \ \  \   \ \\\\     \ \  \  \ \  \
//                              \ \__\   \ \\\\\\\\\\ \__\  \ \__\
//                               \/__/    \/________/\/__/   \/__/
//
