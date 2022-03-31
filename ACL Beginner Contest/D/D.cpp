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
#define MODE 1

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 3e5 + 7;

struct seg {
    int tree[maxn*4] = {};

    int LC(int i) {return i*2;}
    int RC(int i) {return i*2+1;}

    void pull(int l, int r, int i) {
        tree[i] = max(tree[LC(i)], tree[RC(i)]);
    }
    void build( int l, int r, int i=1) {
        if (l == r) {
            tree[i] = 0;
            return;
        }

        int m = (l+r) / 2;
        build(  l, m, LC(i));
        build(m+1, r, RC(i));
        pull(l,r,i);
    }

    void upd( int x, int d, int l, int r, int i=1) {
        if (l == r) {
            tree[i] = d;
            return;
        }

        int m = (l+r) / 2;
        if (x <= m)
            upd(x, d,   l, m, LC(i));
        if (m+1 <= x)
            upd(x, d, m+1, r, RC(i));
        pull(l,r,i);
    }

    int query(int x1, int x2, int l, int r, int i=1) {
        de(0) printf("query(%lld, %lld)\n", l, r);
        de(0) system("PAUSE");
        if (x1 <= l && r <= x2) {
            return tree[i];
        }

        int m = (l+r) / 2;
        int ret = 0;
        if (x1 <= m)
            ret = max(ret, query(x1, x2, l, m, LC(i)));
        if (m+1 <= x2)
            ret = max(ret, query(x1, x2, m+1, r, RC(i)));
        return ret;
    }
}seg;

int A[maxn] = {};

main() {
    int i,j;
    int N,K;

    cin >> N >> K;
    for (int i=1; i<=N; i++) {
        cin >> A[i];
    }

    int M = 300000;
    seg.build(0,M);
    for (int i=1; i<=N; i++) {
        int l = max(0LL, A[i]-K);
        int r = min(M, A[i]+K);
        de(0) printf("YEE\n");
        int q = seg.query(l, r, 0, M);
        seg.upd(A[i], q+1, 0, M);
    }
    int ans = seg.query(0, M, 0, M);
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
