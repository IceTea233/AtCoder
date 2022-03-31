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

int32_t main() {
    cin.tie(0);
    int i,j;
    int N;
    int ans = 0;

    cin >> N;
    for (i=1; i * 10 <= N; i*=10);
    // printf("i = %lld\n", i);

    int cnt = (N - i + 1);
    // printf("cnt = %lld\n", cnt);
    ans += (cnt + 1) % MOD * (cnt % MOD) % MOD * pwr(2, MOD - 2) % MOD;
    ans %= MOD;

    for (; i > 1; i /= 10) {
        cnt = i - i / 10;
        // printf("cnt = %lld\n", cnt);
        ans += (cnt + 1) % MOD * (cnt % MOD) % MOD * pwr(2, MOD - 2) % MOD;
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
