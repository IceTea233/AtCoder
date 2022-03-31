#include<bits/stdc++.h>
#define int long long
#define all(x) begin(x), end(x)
#define SZ(x) ((int)(x).size())
#define EB emplace_back
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define de(x) if(x && x == MODE)
#define MODE 0

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 2e5 + 7;
const int MOD = 998244353LL;

struct SGT {
    int tree[maxn*4] = {};
    int tag[maxn*4] = {};
    int cht[10][maxn] ={};

    SGT() {
        for (int i=1; i<=9; i++) {
            for (int j=1; j<=200000; j++) {
                cht[i][j] = ( cht[i][j-1] * 10 + i ) % MOD;
            }
        }
    }

    int pwr(int x, int k) {
        int ret = 1;
        while(k) {
            if (k&1)
                ret = ret * x % MOD;
            x = x * x % MOD;
            k >>= 1;
        };
        return ret;
    }

    int LC(int i) {return i*2;}
    int RC(int i) {return i*2+1;}

    void push(int l, int r, int i) {
        if (tag[i] == -1)
            return;

        int m = (l+r) / 2;
        tree[LC(i)] = cht[ tag[i] ][m-l+1];
        tree[RC(i)] = cht[ tag[i] ][r-m];
        tag[LC(i)] = tag[i];
        tag[RC(i)] = tag[i];
    }
    void pull(int l, int r, int i) {
        int m = (l+r) / 2;
        tree[i] = ( tree[LC(i)] * pwr(10, r-m) % MOD + tree[RC(i)] ) % MOD;
        if (tag[LC(i)] == tag[RC(i)]) {
            tag[i] = tag[LC(i)];
        } else {
            tag[i] = -1;
        }
    }
    void build(int l, int r, int i=1) {
        if (l == r) {
            tree[i] = 1;
            tag[i] = 1;
            return;
        }
        int m = (l+r) / 2;
        build(l, m, LC(i));
        build(m+1, r, RC(i));
        pull(l, r, i);
    }
    void upd(int x1, int x2, int d, int l, int r, int i=1) {
        if (x1 <= l && r <= x2) {
            tree[i] = cht[d][r-l+1];
            tag[i] = d;
            return;
        }
        int m = (l+r) / 2;
        push(l, r, i);
        if (x1 <= m)
            upd(x1, x2, d, l, m, LC(i));
        if (m+1 <= x2)
            upd(x1, x2, d, m+1, r, RC(i));
        pull(l, r, i);
    }
    int qry() {
        return tree[1];
    }
}seg;

main() {
    int i,j;
    int N,Q;

    cin >> N >> Q;
    seg.build(1,N);
    de(1) printf("%lld\n", seg.qry());
    for (int i=1; i<=Q; i++) {
        int L,R,D;
        scanf("%lld %lld %lld", &L, &R, &D);
        seg.upd(L, R, D, 1, N);
        int q = seg.qry();
        printf("%lld\n", q);
    }

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
