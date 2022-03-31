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
#define R F
#define C S
#define de(x) if(x && x == MODE)
#define MODE 1

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 5e2 + 7;

int H,W;
char grid[maxn][maxn];
bool v[maxn][maxn] = {};
int mask[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool okay(int r, int c) {
    return 1 <= r && r <= H && 1 <= c && c <= W;
}

queue<pii> que;
void dfs(int r, int c) {
    v[r][c] = true;
    que.push({r, c});
    for (int i=0; i<4; i++) {
        int nr = r + mask[i][0];
        int nc = c + mask[i][1];
        if (okay(nr, nc) && grid[nr][nc] == '.' && !v[nr][nc]) {
            dfs(nr, nc);
        }
    }
}

int bfs(int r, int c) {
    dfs(r, c);
    int step = 0;
    while (!que.empty()) {
        int goal = que.size();
        while (goal--) {
            pii cur = que.front();
            que.pop();
            // printf("now (%lld, %lld)\n", cur.R, cur.C);
            if (cur.R == H && cur.C == W)
                return step;
            for (int i=-2; i<=2; i++) {
                for (int j=-2; j<=2; j++) {
                    if (i == -2 && (j == -2 || j == 2) || i == 2 && (j == -2 || j == 2))
                        continue;
                    int nr = cur.R + i;
                    int nc = cur.C + j;
                    if (okay(nr, nc) && !v[nr][nc]) {
                        dfs( nr, nc);
                    }
                }
            }
        }
        step++;
        // printf("step++\n");
    }
    return -1;
}

int32_t main() {
    cin.tie(0);
    int i,j;

    cin >> H >> W;
    for (int i=1; i<=H; i++) {
        scanf("%s", grid[i]+1);
    }
    int ans = bfs(1, 1);
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
