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
const int maxn = 2e3 + 7;

struct edge {
    int des;
    int w;
};
bool operator<(edge a, edge b) {
    return a.w > b.w;
}

int N,M;
vector<edge> G[maxn];
bool v[maxn] = {};
int d[maxn][maxn] = {};
int ans[maxn] = {};

void dijkstra(int s) {
    memset(v, 0, sizeof(v));
    for (int i=1; i<=N; i++)
        d[s][i] = INF;

    priority_queue<edge> pq;
    d[s][s] = 0;
    pq.push({s, 0});
    while (!pq.empty()) {
        int x = pq.top().des;
        pq.pop();

        if (v[x])
            continue;
        v[x] = 1;
        for (auto it : G[x]) {
            int y = it.des;
            int w = it.w;
            if (v[y])
                continue;
            if (d[s][x] + w < d[s][y]) {
                d[s][y] = d[s][x] + w;
                pq.push({y, d[s][y]});
            }
        }
    }
}

int32_t main() {
    int i,j;


    cin >> N >> M;
    for (int i=1; i<=N; i++)
        ans[i] = INF;
    for (int i=1; i<=M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == b)
            ans[a] = min(ans[a], c);
        else
            G[a].PB({b, c});
    }
    for (int i=1; i<=N; i++)
        dijkstra(i);

    // for (int i=1; i<=N; i++) {
    //     for (int j=1; j<=N; j++) {
    //         printf("%lld ", d[i][j] == INF ? -1 : d[i][j]);
    //     }
    //     printf("\n");
    // }

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (i == j)
                continue;
            ans[i] = min(ans[i], d[i][j] + d[j][i]);
        }
    }

    for (int i=1; i<=N; i++) {
        printf("%lld\n", ans[i] == INF ? -1 : ans[i]);
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
