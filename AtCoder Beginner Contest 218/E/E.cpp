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
const int maxn = 2e5 + 7;

struct edge{
    int A;
    int B;
    int C;
    int id;
    bool operator<(edge b) {
        return C < b.C;
    }
};

struct DS {
    int p[maxn] = {};

    DS() {
        for (int i=0; i<maxn; i++)
            p[i] = i;
    }

    int clan(int x) {
        return x == p[x] ? x : (p[x] = clan(p[x]));
    }

    void join(int x, int y) {
        x = clan(x);
        y = clan(y);
        if (x == y)
            return;
        p[y] = x;
    }
} ds;

bool used[maxn] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    int N, M;

    cin >> N >> M;
    vector<edge> E;
    int ans = 0;
    for (int i=1; i<=M; i++) {
        int a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        E.PB({a, b, c, i});
        ans += c;
    }

    sort(all(E));
    for (auto &it : E) {
        if (ds.clan(it.A) != ds.clan(it.B)) {
            ds.join(it.A, it.B);
            used[it.id] = true;
            ans -= it.C;
        }
    }

    for (auto &it : E) {
        if (it.C < 0 && !used[it.id]) {
            ans -= it.C;
        }
    }

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
