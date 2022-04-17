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
#define MODE 1

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 1e5 + 7;
const int MOD = 998244353;

int dp[2507][2501] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    int N, M, K;

    cin >> N >> M >> K;

    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i=0; i < N; i++) {
        for (int j=0; j <= K; j++) {
            for (int k = 1; k <= M && j + k <= K; k++) {
                dp[i + 1][j + k] += dp[i][j];
                dp[i + 1][j + k] %= MOD;
            }
        }
    }

    // for (int i=1; i<=N; i++) {
    //     for (int j=1; j<=K; j++) {
    //         printf("%lld ", dp[i][j]);
    //     }
    //     printf("\n");
    // }

    int ans = 0;
    for (int i=1; i <= K; i++) {
        ans = (ans + dp[N][i]) % MOD;
    }
    printf("%lld\n", ans);

    return 0;
}

/*
          ___ ___  __________  __________
         /////\  \/\   ______\/\\\\\\\\\\\  Code by ~Ice Tea~ of
        //// \ \  \ \  \_____/\ \\\\_____/      New Empire of CHSH ...
       ////   \ \  \ \  \      \ \\\\\\\\\\\
      ////__   \ \  \ \  \      \ \\\\_____/
     ///////\   \ \  \ \  \______\ \\\\_______   ________
    ////____/    \ \__\ \___   ___\ \\\\\\\\\\\ _\  ___  \_
   /__/           \/__/\/__/\  \__/\ \\\\_____//\  .\_/\_  \
                           \ \  \   \ \\\\\\\\\\\\  \_\/_\  \
 ... with the AC Power of   \ \  \   \ \\\\_____/ \   _____  \
   The Great Tsundere Doggy. \ \  \   \ \\\\     \ \  \  \ \  \
                              \ \__\   \ \\\\\\\\\\ \__\  \ \__\
                               \/__/    \/________/\/__/   \/__/
*/
