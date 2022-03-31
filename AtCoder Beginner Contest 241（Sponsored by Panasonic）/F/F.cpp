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
#define x first
#define y second
#define r first
#define c second

#define de(x) if(x && x == MODE)
#define MODE 0

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 1e5 + 7;

int32_t main() {
    cin.tie(0);
    int i,j;
    int H, W, N;
    cin >> H >> W >> N;

    pii s;
    pii g;
    cin >> s.x >> s.y;
    cin >> g.x >> g.y;

    de(1) {
        printf("read.1 ok\n");
    }
    map<int, set<int> > row;
    map<int, set<int> > col;
    map<pii, bool> vis;
    for (int i=1; i<=N; i++) {
        pii obs;
        cin >> obs.x >> obs.y;
        row[obs.x].insert(obs.y);
        col[obs.y].insert(obs.x);
    }

    de(1) {
        printf("read.2 ok\n");
    }

    vis[s] = true;
    queue<pii> que({s});
    int step = 0;
    while (!vis[g] && que.size()) {
        de(1) {
            printf("\nnext step\n");
        }
        int goal = que.size();
        while (goal--) {
            pii cur = que.front();
            de(1) printf("current = (%lld, %lld)\n", cur.r, cur.c);
            que.pop();

            // move up
            auto it = col[cur.c].upper_bound(cur.r);
            if (it != col[cur.c].begin()) {
                pii nxt = (pii) {*prev(it) + 1, cur.c};
                if (!vis[nxt]) {
                    vis[nxt] = true;
                    que.push(nxt);
                }
            }

            // move down
            it = col[cur.c].upper_bound(cur.r);
            if (it != col[cur.c].end()) {
                pii nxt = (pii) {*it - 1, cur.c};
                if (!vis[nxt]) {
                    vis[nxt] = true;
                    que.push(nxt);
                }
            }

            // move left
            it = row[cur.r].upper_bound(cur.c);
            if (it != row[cur.r].begin()) {
                pii nxt = (pii) {cur.r, *prev(it) + 1};
                if (!vis[nxt]) {
                    vis[nxt] = true;
                    que.push(nxt);
                }
            }

            // move right
            it = row[cur.r].upper_bound(cur.c);
            if (it != row[cur.r].end()) {
                pii nxt = (pii) {cur.r, *it - 1};
                if (!vis[nxt]) {
                    vis[nxt] = true;
                    que.push(nxt);
                }
            }
        }
        step ++;
    }

    if (vis[g]) {
        printf("%lld\n", step);
    } else {
        printf("-1\n");
    }

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
