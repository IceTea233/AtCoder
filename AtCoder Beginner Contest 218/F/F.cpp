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
const int maxn = 4e2 + 7;

int N, M;

struct Edge{
    int id;
    int des;
};
vector<Edge> G[maxn];

int solve(int ban) {
    bool vis[maxn] = {};
    queue<int> que;
    que.push(1);
    vis[1] = true;
    int step = 0;
    while (!que.empty() && !vis[N]) {
        int goal = que.size();
        while (goal--) {
            int x = que.front();
            // printf(">>> %lld\n", x);
            que.pop();
            for (auto &to : G[x]) {
                if (to.id != ban && !vis[to.des]) {
                    vis[to.des] = true;
                    que.push(to.des);
                }
            }
        }
        step++;
    }

    if (vis[N])
        return step;
    else
        return -1;
}

int32_t main() {
    cin.tie(0);
    int i,j;

    cin >> N >> M;
    for (int i=1; i<=M; i++) {
        int s, t;
        scanf("%lld %lld", &s, &t);
        G[s].PB({i, t});
    }

    for (int i=1; i<=M; i++) {
        int ans = solve(i);
        printf("%lld\n", ans);
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
