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
const int maxn = 1e5 + 7;

struct ds {
    int p[maxn] = {};

    ds() {
        for (int i=1; i<=maxn; i++) {
            p[i] = i;
        }
    }

    int clan(int x) {
        return x == p[x] ?  x : p[x] = clan(p[x]);
    }

    void join(int x, int y) {
        x = clan(x);
        y = clan(y);
        if (x == y)
            return;
        p[y] = x;
        return;
    }
}ds;

bool v[maxn] = {};

main() {
    int i,j;
    int N, M;

    cin >> N >> M;
    for (int i=1; i<=M; i++) {
        int a,b;
        cin >> a >> b;
        ds.join(a,b);
    }
    int cnt = 0;
    for (int i=1; i<=N; i++) {
        int cl = ds.clan(i);
        if (!v[cl]) {
            v[cl] = 1;
            cnt++;
        }
    }

    printf("%lld\n", cnt-1);

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
