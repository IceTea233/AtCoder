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
const int maxn = 3e5 + 7;
const int MOD = 998244353;

int A[maxn] = {};

struct SGT {
    int tree[maxn*4] = {};
    int tag[maxn*4] = {};
    int LC(int i) {return i*2;}
    int RC(int i) {return i*2+1;}

    void pull(int l, int r, int i) {
        tree[i] = (tree[LC(i)] + tree[RC(i)]) % MOD;
    }

    void push(int l, int r, int i) {
        tree[LC(i)] = tree[LC(i)] * tag[i] % MOD;
        tree[RC(i)] = tree[RC(i)] * tag[i] % MOD;
        tag[LC(i)] = tag[LC(i)] * tag[i] % MOD;
        tag[RC(i)] = tag[RC(i)] * tag[i] % MOD;
        tag[i] = 1;
    }

    void build(int l, int r, int i=1) {
        if (l == r) {
            tree[i] = 0;
            tag[i] = 1;
            return;
        }
        tag[i] = 1;
        int m = (l + r) / 2;
        build(l, m, LC(i));
        build(m+1, r, RC(i));
        pull(l, r, i);
    }

    void upd(int x1, int x2, int l, int r, int i=1) {
        if (x1 <= l && r <= x2) {
            tree[i] = tree[i] * 2 % MOD;
            tag[i] = tag[i] * 2 % MOD;
            return;
        }
        push(l, r, i);
        int m = (l + r) / 2;
        if (x1 <= m)
            upd(x1, x2, l, m, LC(i));
        if (m+1 <= x2)
            upd(x1, x2, m+1, r, RC(i));
        pull(l, r, i);
    }

    void upd2(int x, int l, int r, int i=1) {
        if (l == r) {
            tree[i] = (tree[i] + 1) % MOD;
            return;
        }
        push(l, r, i);
        int m = (l + r) / 2;
        if (x <= m)
            upd2(x, l, m, LC(i));
        if (m+1 <= x)
            upd2(x, m+1, r, RC(i));
        pull(l, r, i);
    }

    int query(int x1, int x2, int l, int r, int i=1) {
        if (x1 <= l && r <= x2) {
            return tree[i];
        }
        push(l, r, i);
        int m = (l + r) / 2;
        int ret = 0;
        if (x1 <= m)
            ret += query(x1, x2, l, m, LC(i));
        if (m+1 <= x2)
            ret += query(x1, x2, m+1, r, RC(i));
        return ret % MOD;
    }
} seg;

int32_t main() {
    cin.tie(0);
    int i,j;
    int N;

    cin >> N;
    for (int i=1; i<=N; i++)
        cin >> A[i];

    vector<int> d;
    for (int i=1; i<=N; i++) {
        d.PB(A[i]);
    }
    sort(all(d));
    d.resize(unique(all(d)) - begin(d));
    // for (auto it : d)
    //     printf("%lld ", it);
    // printf("\n");

    // vector<pii> keep;
    // for (int i=1; i<=N; i++)
    //     keep.PB({i, A[i]});
    // sort(all(keep));

    seg.build(1, N);
    int ans = 0;
    for (int i=1; i<=N; i++) {
        int x = lower_bound(all(d), A[i]) - begin(d) + 1;
        // printf("x = %lld\n", x);
        int add = seg.query(1, x, 1, N);
        // printf("add = %lld\n", add);
        ans = (ans + add) % MOD;
        seg.upd(1, N, 1, N);
        seg.upd2(x, 1, N);
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
