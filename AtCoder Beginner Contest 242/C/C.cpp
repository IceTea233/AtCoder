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
const int maxn = 1e6 + 7;
const int MOD = 998244353;

int dp[maxn][10] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    int N;

    cin >> N;

    for (int i=1; i<=9; i++) {
        dp[1][i] = 1;
    }
    for (int i=2; i<=N; i++) {
        for (int j=1; j<=9; j++) {
            if (j - 1 >= 1) {
                dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
            }
            dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            if (j + 1 <= 9) {
                dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % MOD;
            }
        }
    }

    int ans = 0;
    for (int i=1; i<=9; i++) {
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
