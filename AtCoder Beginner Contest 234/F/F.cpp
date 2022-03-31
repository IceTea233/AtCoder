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
const int maxn = 5e3 + 7;
const int MOD = 998244353;

int cnt[30] = {};
int dp[2][5007] = {};
int frac[maxn] = {};
int cmpl[maxn] = {};

int pwr(int x, int k) {
    int ret = 1;
    while (k) {
        if (k & 1) {
            ret = ret * x % MOD;
        }
        x = x * x % MOD;
        k >>= 1;
    }
    return ret;
}

int inv(int x) {
    return pwr(x, MOD - 2);
}

void prepare() {
    frac[0] = 1;
    cmpl[0] = inv(frac[0]);
    for (int i=1; i<maxn; i++) {
        frac[i] = frac[i-1] * i % MOD;
        cmpl[i] = inv(frac[i]);
    }
}

int C(int u, int d) {
    return frac[u] * cmpl[d] % MOD * cmpl[u - d] % MOD;
}

int H(int u, int d) {
    return C(u + d - 1, d);
}

void upd(int src, int len, int cur, int add) {
    dp[cur&1][len + add] += dp[src&1][len] * H(len + 1, add) % MOD;
    dp[cur&1][len + add] %= MOD;
}

int32_t main() {
    cin.tie(0);
    int i,j;
    string s;

    cin >> s;
    int n = s.size();
    prepare();
    for (auto &it : s) {
        cnt[it - 'a' + 1] ++;
    }

    dp[0][0] = 1;
    for (int i=1; i<=26; i++) {
        for (int j=0; j<=n; j++) {
            dp[i&1][j] = 0;
        }

        for (int j=0; j<=cnt[i]; j++) {
            for (int k=0; k <= n - j; k++) {
                upd(i-1, k, i, j);
            }
        }
        // printf(">>> ");
        // for (int j=0; j<=n; j++) {
        //     printf(" %lld", dp[i&1][j]);
        // }
        // printf("\n");
    }

    int ans = 0;
    for (int i=1; i<=n; i++) {
        ans += dp[26&1][i];
        ans %= MOD;
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
