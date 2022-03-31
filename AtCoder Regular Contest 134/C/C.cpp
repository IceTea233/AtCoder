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

int a[maxn] = {};
int frac[maxn] = {};
int inv[maxn] = {};

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

void prepare() {
    frac[0] = 1;
    inv[0] = 1;
    for (int i = 1; i <= 200; i++) {
        frac[i] = frac[i-1] * i % MOD;
        // inv[i] = pwr(frac[i], MOD - 2);
    }
}

int C(int u, int d) {
    if (u - d < d) {
        d = u - d;
    }
    // cerr << "C(" << u << ", " << d << ")\n";

    int ret = 1;
    for (int i=0; i < d; i++) {
        // cerr << "i = " << i << "\n";
        ret = ret * ((u - i) % MOD) % MOD;
        ret = ret * pwr(i + 1, MOD - 2) % MOD;
    }
    // ret = ret * pwr(frac[d], MOD - 2);

    return ret;
}

int H(int u, int d) {
    return C(u + d - 1, d);
}

int32_t main() {
    cin.tie(0);
    int i, j;
    int N, K;

    // prepare();
    cin >> N >> K;
    for (int i=1; i<=N; i++) {
        cin >> a[i];
    }

    int ett = 0;
    for (int i=2; i<=N; i++) {
        ett += a[i];
    }

    // cerr << "OK\n";

    if (a[1] < ett + K) {
        printf("0\n");
        return 0;
    }

    int ans = 1;
    for (int i=2; i <= N; i++) {
        ans = ans * H(K, a[i]) % MOD;
    }

    // cerr << "OK #2\n";
    ans = ans * H(K, a[1] - (ett + K)) % MOD;
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
