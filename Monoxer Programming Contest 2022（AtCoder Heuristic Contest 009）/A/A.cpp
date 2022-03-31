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
#define MODE 0

#define r F
#define c S

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 1e5 + 7;

bool wall[27][27][4]; // {D, R, U, L}
const int mask[4][2] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
};

const int D = 0;
const int R = 1;
const int U = 2;
const int L = 3;

int sr, sc;
int tr, tc;
double p;

void input() {
    cin >> sr >> sc >> tr >> tc >> p;

    de(1) printf("#1 OK\n");

    for (int i=0; i<20; i++) {
        string row;
        cin >> row;
        wall[i][0][L] = true;
        for (int j=0; j<20; j++) {
            if (j == 19) {
                wall[i][j][R] = true;
            } else {
                int h = row[j] - '0';
                // cin >> h;
                if (h) {
                    wall[i][j][R] = true;
                    wall[i][j+1][L] = true;
                }
            }
        }
    }

    de(1) printf("#2 OK\n");

    for (int i=0; i<20; i++) {
        string row;
        if (i < 19)
            cin >> row;

        for (int j=0; j<20; j++) {
            if (i == 0)
                wall[i][j][U] = true;

            if (i == 19) {
                wall[i][j][D] = true;
            } else {
                int v = row[j] - '0';
                // cin >> v;
                if (v) {
                    wall[i][j][D] = true;
                    wall[i+1][j][U] = true;
                }
            }
        }
    }

    de(1) {
        for (int i=0; i<20; i++) {
            for (int j=0; j<20; j++) {
                printf("(%lld, %lld): wall(%lld, %lld, %lld, %lld)\n", i, j,
                    (int) wall[i][j][D], (int) wall[i][j][R], (int) wall[i][j][U], (int) wall[i][j][L]);
            }
        }
    }
}

string solve() {
    bool vis[27][27] = {};
    int p[27][27] = {};

    queue<pii> que;
    que.push((pii) {sr, sc});

    de(1) printf("#3 OK\n");

    int step = 0;
    while (que.size() && step < 200 && !vis[tr][tc]) {
        int goal = que.size();
        while (goal--) {
            pii cur = que.front();
            que.pop();
            de(1) printf("cur = (%lld, %lld)\n", cur.r, cur.c);

            for (int i=0; i<4; i++) {
                if (wall[cur.r][cur.c][i])
                    continue;

                int nr = cur.r + mask[i][0];
                int nc = cur.c + mask[i][1];

                if (!vis[nr][nc]) {
                    vis[nr][nc] = true;
                    p[nr][nc] = i;
                    de(1) printf("p[%lld][%lld] = %lld(%lld)\n", nr, nc, p[nr][nc], i);
                    que.push({nr, nc});
                }
            }
        }

        de (1) printf("\n");
        step++;
    }

    de (1) printf("#4 OK\n");

    string ans;
    if (!vis[tr][tc]) {
        ans = "D";
    } else {
        int cur_r = tr;
        int cur_c = tc;
        while (!(cur_r == sr && cur_c == sc)) {
            assert(vis[cur_r][cur_c] == true);

            int cmd = p[cur_r][cur_c];

            switch (cmd) {
                case D: ans.PB('D'); break;
                case R: ans.PB('R'); break;
                case U: ans.PB('U'); break;
                case L: ans.PB('L'); break;
            }
            cur_r -= mask[cmd][0];
            cur_c -= mask[cmd][1];

            de(1) printf("cmd = %lld, cur = (%lld, %lld)\n", cmd, cur_r, cur_c);
        }
    }
    reverse(all(ans));

    de(1) printf("#5 OK\n");

    return ans;
}

int32_t main() {
    cin.tie(0);
    int i,j;

    input();
    string ans = solve();
    cout << ans << "\n";

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
